#include <raylib.h>
#include "player.h"
#include "tile.h"

class Ball{
	public:
		Ball(int _screenX, int _screenY, PongPlayer *_player);		
		

		/* constants */
		struct Vector2 screenEdges[4]; 
		const float radius = 10.0f;
		const struct Color color = RED;
		
		/* Variables */
		struct Vector2 speed = {5,5};
		struct Vector2 position={500,100};

		PongPlayer *player;

		/*Functions*/
		void Move();
		void Bounce(bool bounceX, bool bounceY);
	private:
		void CheckCollision();

};
