#include "tile.h"

Tile::Tile(struct Vector2 _position)
{
	position = _position;

	points[0] = Vector2{position.x, position.y };
	points[1] = Vector2{position.x , position.y + size.y};
	points[2] = Vector2{position.x + size.x, position.y + size.y};
	points[3] = Vector2{position.x + size.x, position.y};
}

Tile::Tile()
{}

void Tile::Place()
{
	if (isAlive)
		DrawRectangleV(position,size,color);
}

void Tile::Die()
{
	isAlive = false;
}
