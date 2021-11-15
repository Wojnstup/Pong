#include <raylib.h>
#include "player.h"
#include "tile.h"

class Ball{
	public:
		Ball(int _screenX, int _screenY, PongPlayer *_player, Tile (*_tiles)[55]);		
		

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
		Tile (*tiles)[55];

		/*Functions*/
		void Move();
		void Bounce(bool bounceX, bool bounceY);
	private:
		int DistanceLinePoint(struct Vector2 point, struct Vector2 lineStart, struct Vector2 lineEnd);
		void CheckCollision();
		void GetNewPos();		

};
