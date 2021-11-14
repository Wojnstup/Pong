#include "player.h"

PongPlayer::PongPlayer()
{

}

void PongPlayer::FollowMouse()
{
	position.x = GetMouseX() - width/2;
	DrawRectangleV(position, Vector2{width, height}, color );	
}	

