#include "ball.h"

Ball::Ball(int _screenX, int _screenY, PongPlayer *_player, Tile (*_tiles)[55])
{
	screenEdges[0] = Vector2{0,0};
	screenEdges[1] = Vector2{0,_screenY};
	screenEdges[2] = Vector2{_screenX, _screenY};
	screenEdges[3] = Vector2{_screenX,0};	
	player = _player;
	tiles = _tiles;
};

void Ball::Move()
{
	CheckCollision();
	position.x += speed.x;
	position.y += speed.y;

	DrawCircle(position.x,position.y,radius, color);
}

void Ball::Bounce(bool bounceX, bool bounceY)
{
	if (bounceX)
		speed.x = 0 - speed.x;
	if (bounceY)
		speed.y = 0 - speed.y;
}

void Ball::GetNewPos()
{
	newPos = { position.x + speed.x, position.y + speed.y};
}

int Ball::DistanceLinePoint(struct Vector2 point, struct Vector2 lineStart, struct Vector2 lineEnd)
{
	
}

void Ball::CheckCollision()
{
	GetNewPos();

	/* Sides of the screen */
	if ( screenEdges[2].x - newPos.x < radius || newPos.x - screenEdges[0].x < radius )	
		Bounce(true,false);
	if ( newPos.y - screenEdges[0].y < radius)
		Bounce(false,true);
	/* Player */
	if ( CheckCollisionCircleRec(newPos, radius, Rectangle{player->position.x, player->position.y, player->width, player->height} ) )
		Bounce(false,true);

	/* Tiles */
	for ( int i=0; i<55; i++ )
	{
		Tile tile = (*tiles)[i];
		if( tile.isAlive && CheckCollisionCircleRec(newPos, radius, Rectangle{tile.position.x, tile.position.y, tile.size.x, tile.size.y} ))
		{
			if (!CheckCollisionCircleRec(Vector2{newPos.x, newPos.y - (2*speed.y) }, radius, Rectangle{tile.position.x, tile.position.y, tile.size.x, tile.size.y} ))
				Bounce(false,true);
			else if(!CheckCollisionCircleRec(Vector2{newPos.x - (2*speed.x), newPos.y}, radius, Rectangle{tile.position.x, tile.position.y, tile.size.x, tile.size.y} ))
				Bounce(true,false);
			else if(!CheckCollisionCircleRec(Vector2{newPos.x - (2*speed.x), newPos.y - (2*speed.y) }, radius, Rectangle{tile.position.x, tile.position.y, tile.size.x, tile.size.y} ))
				Bounce(true,true);


			(*tiles)[i].Die();
		}

	}

}


