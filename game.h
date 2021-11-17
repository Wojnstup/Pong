#include "raylib.h"
#include "ball.h"

class Game{
	public:
		Game(int _screenWidth, int _screenHeight);
		void Loop();

		int screenWidth;
		int screenHeight;

		PongPlayer player;
		static const int tileNum=55;
		Tile tiles[tileNum];
		int tileRow = 0;
		int tileColumn = 20;
		Ball *ball; //, , &player, &tiles);
};
