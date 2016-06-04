#include "Bullet.h"
#include <iostream>
using namespace std;

short Bullet::shadow_wait = 0;
void Bullet::move(){
	switch (dir){
	case LEFT:xpos -= 2; break;
	case RIGHT:xpos += 2; break;
	case DOWN:ypos++; break;
	case UP:ypos--; break;
	case LEFTDOWN: xpos--; ypos++; break;
	case RIGHTDOWN:xpos++; ypos++; break;
	case LEFTUP: xpos--; ypos--; break;
	case RIGHTUP:xpos++; ypos--; break;
	case ARROUND1:xpos += rand() % 2; ypos += rand() % 2; break;
	case ARROUND2:xpos -= rand() % 2; ypos += rand() % 2; break;
	case SHADOW:
		ypos--;
		break;
	default:break;
	}
}
void Bullet::set_char(char sig){
	ch = sig;
}
void Bullet::updata(){
	if (alive){
		if (dir == SHADOW){
			battlefield[ypos][xpos] = ch;
			battlefield[ypos][xpos-1] = '>';
			battlefield[ypos][xpos+1] = '<';
		}
		else
			battlefield[ypos][xpos] = ch;
	}
}
int Bullet::hurt(int x, int y){
	if (x == xpos && y == ypos){
		switch (kind){
		case PONE:return 10;//bkind=0
		case PTWO:return 20;//1
		case PTHREE:return 30;//2
		case PFOUR:return 50;//3
		case EONE:return 5;
		case ETWO:return 15;
		case ETHREE:return 25;
		case EFOUR:return 50;
		case PLOVE:return 60;//8
		default:return 0;
		}
	}
	else
		return 0;
}
bool Bullet::inscreen(){
	if ((alive) && (xpos >= 0) && (xpos < WIDTH) && (ypos >= 0) && (ypos < HEIGHT))return true;
	else return false;
}