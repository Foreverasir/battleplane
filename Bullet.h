#pragma once
#include "SomeConst.h"

class Bullet{
	int xpos, ypos;
	char ch;
	bool alive;
	static short shadow_wait;
public:
	enum Direction;
	Direction dir;
	enum BKIND;
	BKIND kind;
	enum BKIND{ PONE, PTWO, PTHREE, PFOUR, EONE, ETWO, ETHREE, EFOUR, PLOVE };
	enum Direction{ LEFT, RIGHT, DOWN, UP, LEFTDOWN, RIGHTDOWN, LEFTUP, RIGHTUP, ARROUND1,ARROUND2,SHADOW };
	Bullet(){ xpos = 0; ypos = 0; dir = DOWN; ch = '.'; kind = PONE; }
	Bullet(int x, int y, Direction dirc, char sig,short k){
		xpos = x;ypos = y;
		dir = dirc;ch = sig;alive = true;
		kind = (BKIND)k;
	}
	int getPosX()const{ return xpos; }
	int getPosY()const{ return ypos; }
	bool get_alive(){ return alive; }
	void kill(){ alive = false; }//用于碰撞
	void move();
	void set_char(char sig);
	void updata();
	int hurt(int x, int y);
	bool inscreen();//用于list中删除
};