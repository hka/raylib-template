#ifndef KORTSPEL_SCREENS_H
#define KORTSPEL_SCREENS_H

#include "raylib.h"

#include <stdlib.h>
#include <string>
#include <memory>
#include <vector>

#include "GuiHelper.h"

struct GameOptions
{
  int screenWidth = 1280;
  int screenHeight = 720;
  int fps = 60;
  bool skipLogo = false;
};

class Screen
{
 public:
  enum class GameScreen { LOGO,
                          TITLE,
                          NOSCREEN };
  virtual void Update() = 0;
  virtual void Paint() = 0;
  virtual GameScreen Finish() = 0;
  virtual GameScreen GetEnum() = 0;
};

class LogoScreen : public Screen
{
 public:
  LogoScreen();
  ~LogoScreen();
  void Init();
  void Update();
  void Paint();
  void Unload();
  GameScreen Finish();
  GameScreen GetEnum(){return Screen::GameScreen::LOGO;}
 private:
  int m_framesCounter;
  GameScreen m_finishScreen;

  int m_logoPositionX;
  int m_logoPositionY;

  int m_lettersCount;

  int m_topSideRecWidth;
  int m_leftSideRecHeight;

  int m_bottomSideRecWidth;
  int m_rightSideRecHeight;

  int m_state;
  float m_alpha;
};

class TitleScreen : public Screen
{
 public:
  TitleScreen();
  ~TitleScreen();
  void Update();
  void Paint();
  GameScreen Finish();
  GameScreen GetEnum(){return Screen::GameScreen::TITLE;}
 private:
  GameScreen m_finishScreen;
  std::vector<Button> m_buttons;
};

// Globals
extern std::unique_ptr<Screen> currentScreen;
extern GameOptions options;
#endif
