#include "Good.h"
#include"Myplane.h"
#include<iostream>

bool Good::b_flag = 0;

Good::Good(){
	int index = rand() % 14;
	if (index >11)//1
		gkind = LIFE;
	else if (index > 8)//3
		gkind = BLOODE;
	else if (index > 5)//3
		gkind = ZHADAN;
	else if (index > 1){
		if (b_flag == false){
			gkind = BULLET1;
			b_flag = true;
		}
		else{
			gkind = BULLET2;
			b_flag = false;
		}
	}
	else gkind = MAGIC;//2
	xpos = rand() % 48;
	ypos = 0;
}
void Good::move(){
	if (rand() % 2 == 1){
		ypos++;
		if (rand() % 2 == 0 && (xpos + 1) < 48)
			xpos++;
		else if (xpos - 1 >= 0)
			xpos--;
	}
}
bool Good::increase(Myplane &p){
	if (p.still_alive() && ((xpos == p.getPosX()) || (xpos == (p.getPosX() - 1)) || (xpos == (p.getPosX() + 1)))
		&& ((ypos == p.getPosY()) || (ypos == (p.getPosY() - 1)) || (ypos == (p.getPosY() + 1)))){
		switch (gkind){
		case LIFE:p.add_life(); break;
		case BLOODE:p.add_blood(50); break;
		case ZHADAN:p.add_bomb(); break;
		case BULLET1:p.change_bullet1(); break;
		case BULLET2:p.change_bullet2(); break;
		case MAGIC:p.add_magic(rand() % 9); break;
		default:break;
		}
		return true;
	}
	else
		return false;
}
void Good::update(){
	if (inscreen()){
		switch (gkind){
		case LIFE:
			battlefield[ypos][xpos] = '\3';
			battlefield[ypos-1][xpos] = '\3';
			battlefield[ypos+1][xpos] = '\3';
			break;
		case BLOODE:
			battlefield[ypos][xpos] = '%'; 
			battlefield[ypos-1][xpos] = '%';
			battlefield[ypos+1][xpos] = '%';
			break;
		case ZHADAN:
			battlefield[ypos][xpos] = '\5'; //²Ý»¨
			battlefield[ypos-1][xpos] = '\5';
			battlefield[ypos+1][xpos] = '\5';
			break;
		case BULLET1:
			battlefield[ypos][xpos] = '\2'; 
			battlefield[ypos+1][xpos] = '\2';
			battlefield[ypos-1][xpos] = '\2';
			break;
		case BULLET2:
			battlefield[ypos][xpos] = '\1'; 
			battlefield[ypos+1][xpos] = '\1';
			battlefield[ypos-1][xpos] = '\1';
			break;
		case MAGIC:
			battlefield[ypos][xpos] = '\6'; 
			battlefield[ypos+1][xpos] = '\6';
			battlefield[ypos-1][xpos] = '\6';
			break;
		default:break;
		}
	}
}
bool Good::inscreen(){
	if ((xpos >= 0) && (xpos < WIDTH) && (ypos >= 0) && (ypos < HEIGHT))return true;
	else return false;
}