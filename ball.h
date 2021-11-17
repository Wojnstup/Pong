#include <raylib.h>
#include "player.h"
#include "tile.h"
#include "config.h"

class Ball{
	public:
		Ball(PongPlayer *_player, Tile (*_tiles)[55]);		
		Ball(){};
		

		/* constants */
		struct Vector2 screenEdges[4]; 
		const float radius = 10.0f;
		const struct Color color = RED;
		
		/* Variables */
		struct Vector2 speed = {4,4};
		struct Vector2 position={500,500};
		struct Vector2 newPos;

		/* References */
		PongPlayer *player;
        Tile (*tiles)[TILE_NUM];

		/*Functions*/
		void Move();
		void Bounce(bool bounceX, bool bounceY);
	private:
		void CheckCollision();
		void GetNewPos();		

};
