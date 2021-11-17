#include "raylib.h"
#include "game.h"
#include "button.h"

class Menu{
	public:
		Menu(int _screenWidth, int _screenHeight);	

		/* Variables */

		int screenWidth;
		int screenHeight;

		Button play; 

		void Display();
	private:
		void StartGame();




};
