#pragma once
#include "Myplane.h"
#include "SomeConst.h"
#include <windows.h>
#include <list>
#include "Bullet.h"
using namespace std;
class Myplane;
class Enemy{
private:
	int x, y;
	short bkind;
	short speed;
	short move_wait;
	ENEMYKIND ekind;
protected:
	list<Bullet*> bullets;
	int alive;
public:
	Enemy(){ x = y = 0; speed = 0; alive = 20; move_wait = 0; }
	Enemy(int sx, int sy,short kind);
	~Enemy(void){};
	int getPosX(){ return x; }
	int getPosY(){ return y; }
	bool still_alive(){
		if (alive > 0)return true;
		return false;
	}
	int give_score();
	virtual void move(short count,Myplane &p);
	void clever_move(Myplane &p);
	virtual void update();//更新飞机以及其子弹
	virtual void reduce_life(Myplane &p);
	virtual int hurt(int x, int y);
	int hurt0(int x, int y);
	virtual void shoot();
	void clear_bullet();
	list<Bullet*> & get_bullets(){ return bullets; }
	friend Game_run;
	friend Myplane;
};