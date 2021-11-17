#include "raylib.h"
#include <string>

class Button{
	public:
  		Button( int _x, int _y, int _width, int _height, std::string _label, struct Vector2 _textPadding);
		
        bool isPressed();
		void Draw();
	private:
		struct Vector2 position;
		struct Vector2 size;
        std::string label;

  		struct Vector2 textPadding;
};
