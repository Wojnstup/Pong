#include <raylib.h>
#include "menu.h"
#include "config.h" 

int main()
{

	InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Pong");
	SetTargetFPS(60);

	Menu menu;
	menu.Display();

}
