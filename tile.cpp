#include "tile.h"

Tile::Tile(struct Vector2 _position)
{
	position = _position;
}

Tile::Tile()
{}

void Tile::Place()
{
	DrawRectangleV(position,size,color);
}
