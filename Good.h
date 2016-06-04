#pragma once
#include"Myplane.h"
#include "SomeConst.h"

class Good{
private:
	int xpos, ypos;
	GOODKIND gkind;
	static bool b_flag;
public:
	Good();
	~Good(){};
	void move();
	bool increase(Myplane &p);
	void update();
	bool inscreen();
};