#include <iostream>
#include "Display.h"
#include "SomeConst.h"
#include "Game_run.h"
using namespace std;
int main(){
	HideCursor();
	drawMenu();
	Start_display();
	while (1){
		Game_run game;
		game.game_run();
	}
}