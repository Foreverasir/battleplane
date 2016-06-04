#ifndef _GAME_RUN_
#define _GAME_RUN_

#include <iostream>
#include <windows.h>
#include "SomeConst.h"
#include "Myplane.h"
#include "Enemy.h"
#include "Good.h"
#include "Magic.h"
#include "stdlib.h"
#include "Boss.h"
using namespace std;

class Game_run{
private:
	short enemy_born;
	Myplane player;
	SHORT states[14];//key state
	list<Enemy*>  enemy_list;
	list<Good*> good_list;
	static int time_wait;
public:
	Game_run();
	~Game_run();
	int game_run();//run the game
	void check_keyboard_input();//check the keyboard input
	void update();//update everything
	void update_2(Boss *b);
	void add_enemy();
	Boss* add_boss();
	void move_clear_enemy();
	bool check_crash();
	bool check_life();
	void check_bomb();
	void check_magic(Magic &m);
	void add_good();
	void move_clear_good();
	void pause();
	bool boss_run(Boss* b);
	void boss_die();
};
#endif