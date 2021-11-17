#include "raylib.h"
#include "game.h"
#include "button.h"

class Menu{
	public:
		Menu();	

		/* Variables */

		Button play; 
  		Button quit;

		void Display();
	private:
		void StartGame();




};
