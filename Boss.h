#pragma once
#include "Enemy.h"

class Boss :public Enemy{
private:
	short shoot_wait;
public:
	Boss();
	void update();
	void shoot();
	int hurt();
	void reduce_life(Myplane &p);
	friend Game_run;
	friend Myplane;
};