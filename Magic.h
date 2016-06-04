#pragma once
#include "SomeConst.h"
#include "Bullet.h"
#include "Myplane.h"
#include <list>
#include <iostream>
using namespace std;

class Magic{
private:
	short mkind;
	list<Bullet*> mbullets;
public:
	Magic(){ mkind = 0; }
	~Magic(){};
	void m1(Myplane &p);
	void m2(Myplane &p);
	void m3(Myplane &p);
	void m4(Myplane &p);
	void m5(Myplane &p);
};
