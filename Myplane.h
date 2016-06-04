#pragma once
#include "Enemy.h"
#include "SomeConst.h"
#include <windows.h>
#include <list>
#include "Bullet.h"
using namespace std;
class Enemy;
class Myplane{
	int x, y;
	int alive;
	int life;
	int score;
	short bomb;
	short bkind; short blines;
	short m1, m2, m3, m4, m5;
	list<Bullet*> bullets;//使用list 双向链表容器
public:
	Myplane(int sx, int sy);
	~Myplane(void){};
	int getPosX(){ return x; }
	int getPosY(){ return y; }
	bool still_alive(){
		if (alive > 0)return true;
		return false;
	}
	void move(SHORT *stas);//根据键盘输入，进行移动
	void update();//更新飞机以及其子弹
	bool next_life();
	void gain_score(int sc){ score += sc; }
	void move_bullet();
	int hurt(int x, int y);
	void shoot();
	void Bomb();
	void clear_bullet();
	void reduce(Enemy *e);
	void add_life(){ life++; }
	void add_bomb(){ bomb++; }
	void add_magic(int i); 
	void change_bullet1(){ if (bkind < 3)bkind++; }
	void change_bullet2(){ if (blines < 7)blines += 2; }
	void add_blood(int ad){ alive += ad; };
	list<Bullet*> & get_bullets(){ return bullets; }
	friend Game_run;
	friend Magic;
};