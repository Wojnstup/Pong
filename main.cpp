#include <raylib.h>
#include "ball.h"

int main()
{
	const int screenWidth = 1080;
	const int screenHeight = 720;

	InitWindow(screenWidth, screenHeight, "Pong");
	SetTargetFPS(60);

	static PongPlayer player;
	
	/* Tiles */
	const int tileNum=55;
	static Tile tiles[tileNum];
	int tileRow = 0;
	int tileColumn = 20;
	for (int i=0; i<tileNum; i++)
	{
		tiles[i]= Tile(Vector2{ tileColumn*80 + (tileColumn+1)*34, tileRow*40 + (tileRow+1)*10 } );
		tileColumn++;
		if (i%9 == 0)
		{
			tileRow++;
			tileColumn=0;	
		}
		
	}

	static Ball ball(screenWidth, screenHeight, &player, &tiles);

	while(!WindowShouldClose())
	{
		BeginDrawing();
			ClearBackground(Color{255,255,255,255});
			player.FollowMouse();

			for( Tile tile : tiles )
			{
				tile.Place();
			}

			ball.Move();
			
		EndDrawing();
		
	}

	CloseWindow();


}
