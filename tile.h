#include "raylib.h"

class Tile{
	public:
		Tile(struct Vector2 _position);
		Tile();

		struct Color color = BLUE;
		struct Vector2 position;
		struct Vector2 size = {70,20};
		
		bool isAlive = true;

		/* Functions */
		void Place();
		void Die();


};
