#include "raylib.h"

class PongPlayer{
	public:
		PongPlayer();
		const int width = 100;
		const int height = 10;
		const struct Color color = BLUE;

		struct Vector2 position = {540, 710};

		void FollowMouse();

};
