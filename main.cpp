#include <raylib.h>
#include "menu.h"
#include <iostream>

int main()
{
 
	const int screenWidth = 1080;
	const int screenHeight = 720;

	InitWindow(screenWidth, screenHeight, "Pong");
	SetTargetFPS(60);

	Menu menu(screenWidth, screenHeight);

	menu.Display();

}
