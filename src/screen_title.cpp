#include "screens.h"

#include "GuiHelper.h"

TitleScreen::TitleScreen()
{
  m_finishScreen = Screen::GameScreen::TITLE;

  Button b;
  float x = options.screenWidth/2.f - 45;
  float y = options.screenHeight/2.f - 45;
  float w = 40;
  float h = 40;
  b.pos = {x, y, w, h};
  m_buttons.resize(4);
  for(size_t r = 0; r < 2; ++r)
  {
    for(size_t c = 0; c < 2; ++c)
    {
      b.pos.x = x + c*50;
      b.pos.y = y + r*50;
      m_buttons[r*2 + c] = b;
    }
  }
}

TitleScreen::~TitleScreen()
{
}

void TitleScreen::Update()
{
  Vector2 mousePoint = GetMousePosition();
  for(auto& b : m_buttons)
  {
    bool buttonPressed = CheckButton(mousePoint, b);
    if(buttonPressed)
    {
      ++b.clickState;
      b.clickState = b.clickState > 2 ? 0 : b.clickState;
    }
  }
}

void TitleScreen::Paint()
{
  DrawRectangle(0, 0, options.screenWidth, options.screenHeight, GREEN);

  for(const auto& b : m_buttons)
  {
    PaintButton(b);
  }
}

Screen::GameScreen TitleScreen::Finish()
{
  return m_finishScreen;
}
