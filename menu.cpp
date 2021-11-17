#include "menu.h"

Menu::Menu()
  :play(700,400,300,100, "Play", Vector2{100,30}),
  quit(700,550,300,100, "Quit", Vector2{100,30})
{
}

void Menu::Display()
{
	while(!WindowShouldClose())
	{
		BeginDrawing();
			ClearBackground(Color{255,255,255,255});	
			play.Draw();
			quit.Draw();
			if (play.isPressed())
			{
				break;
			}
			else if (quit.isPressed())
			{
			  	return;
			}
		EndDrawing();
	}
	StartGame();
}

void Menu::StartGame()
{
	Game game;
	game.Loop();
}
