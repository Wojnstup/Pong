#include "menu.h"

Menu::Menu(int _screenWidth, int _screenHeight)
  :play(700,600,300,100, "Play")
{
	screenWidth = _screenWidth;
	screenHeight = _screenHeight;
}

void Menu::Display()
{
	while(!WindowShouldClose())
	{
		BeginDrawing();
			ClearBackground(Color{255,255,255,255});	
			play.Draw();
			if (play.isPressed())
			{
				break;
			}
		EndDrawing();
	}
	StartGame();
}

void Menu::StartGame()
{
	Game game(screenWidth, screenHeight);
	game.Loop();
}
