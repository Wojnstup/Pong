#include "ball.h"

Ball::Ball(int _screenX, int _screenY, PongPlayer *_player)
{
	screenEdges[0] = Vector2{0,0};
	screenEdges[1] = Vector2{0,_screenY};
	screenEdges[2] = Vector2{_screenX, _screenY};
	screenEdges[3] = Vector2{_screenX,0};	
	player = _player;

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

void Ball::CheckCollision()
{
	struct Vector2 newPos = { position.x + speed.x, position.y + speed.y};
	
	if ( screenEdges[2].x - newPos.x < radius || newPos.x - screenEdges[0].x < radius )	
		Bounce(true,false);
	if ( newPos.y - screenEdges[0].y < radius)
		Bounce(false,true);
	if ( CheckCollisionCircleRec(newPos, radius, Rectangle{player->position.x, player->position.y, player->width, player->height} ) )
		Bounce(false,true);
}


