#include "game.h"

Game::Game()
{
	int tileRow = 0;
	int tileColumn = 20;
	for (int i=0; i<TILE_NUM; i++)
	{
		tiles[i]= Tile(Vector2{ tileColumn*80 + (tileColumn+1)*34, tileRow*40 + (tileRow+1)*10 } );
		tileColumn++;
		if (i%9 == 0)
		{
			tileRow++;
	        	tileColumn=0;
	        }
	}
	ball = new Ball(&player, &tiles);
}

void Game::Loop()
{

	while(!WindowShouldClose())
	{
		BeginDrawing();
			ClearBackground(Color{255,255,255,255});

			player.FollowMouse();

			for( Tile tile : tiles )
			{
				tile.Place();
			}

			ball->Move();

		EndDrawing();
	}
	CloseWindow();
}
