#include "GuiHelper.h"

#include <cstring>

void PaintButton(const Button& button)
{
  //Button
  switch(button.state)
  {
   case MouseState::NO:
     DrawRectangleRec(button.pos, LIME);
     break;
   case MouseState::CLICKED:
     DrawRectangleRec(button.pos, GOLD);
     break;
   case MouseState::OVER:
     DrawRectangleRec(button.pos, GRAY);
     break;
  }
  if(button.clickState == 1)
  {
    DrawRectangleRec(button.pos, BLUE);
  }
 }

bool CheckButton(const Vector2& p, Button& button)
{
  if (CheckCollisionPointRec(p, button.pos))
  {
    if (IsMouseButtonDown(MOUSE_BUTTON_LEFT))
    {
      button.state = MouseState::CLICKED;
    }
    else
    {
      button.state = MouseState::OVER;
    }
    if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT))
    {
      return true;
    }
  }
  else
  {
    button.state = MouseState::NO;
  }
  return false;
}
