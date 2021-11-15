#include "raylib.h"

class Tile{
	public:
		Tile(struct Vector2 _position);
		Tile();

		struct Color color = BLUE;
		struct Vector2 position;
		struct Vector2 size = {80,40};
		
		bool isAlive = true;

		struct Vector2 points[4];

		/* Functions */
		void Place();
		void Die();


};
