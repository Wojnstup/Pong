#include "raylib.h"
#include "ball.h"
#include "config.h"

class Game{
	public:
		Game();
		void Loop();

		PongPlayer player;

		Tile tiles[TILE_NUM];

		Ball *ball; //, , &player, &tiles);
};
