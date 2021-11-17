#include "button.h"

Button::Button(int _x, int _y, int _width, int _height, std::string _label, struct Vector2 _textPadding)
{
	size = Vector2{_width, _height};
	position = Vector2{_x, _y};
	label = _label;
	textPadding = _textPadding;
}

void Button::Draw()
{
	DrawRectangleV(position,size, GRAY);
	DrawText(label.c_str(), position.x + textPadding.x, position.y + textPadding.y, 40, RED);
}

bool Button::isPressed()
{
	return CheckCollisionPointRec( Vector2{GetMouseX(),GetMouseY()}, Rectangle{position.x,position.y,size.x,size.y} ) && IsMouseButtonPressed(0);
}
