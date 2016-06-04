#include "Boss.h"
using namespace std;

Boss::Boss():Enemy(23,0,8){
	shoot_wait = 0;
}
void Boss::update(){
	Enemy::update();
	int x = getPosX();
	int y = getPosY();
	battlefield[y][x - 3] = 'S'; battlefield[y][x - 2] = 'e';
	battlefield[y][x - 1] = 'g'; battlefield[y][x] = 'm';
	battlefield[y][x + 1] = 'e'; battlefield[y][x + 2] = 'n';
	battlefield[y][x + 3] = 't'; battlefield[y + 1][x - 2] = 'F';
	battlefield[y + 1][x - 1] = 'a'; battlefield[y + 1][x] = 'u';
	battlefield[y + 1][x + 1] = 'l';battlefield[y + 1][x + 2] = 't';
	for (int i = 0; i < 3; i++){
		int j = x - 12 - 3*i;
		battlefield[y + i][j] = '/';
		for (; j < x - 4 - 5 * i; j++){
			battlefield[y + i][j + 1] = '=';
		}
		battlefield[y + i + 1][j] = '+';
	}
	for (int i = 0; i < 3; i++){
		int j = x + 12 + 3 * i;
		battlefield[y + i][j] = '\\';
		for (; j > x + 4 + 5 * i; j--){
			battlefield[y + i][j - 1] = '=';
		}
		battlefield[y + i + 1][j] = '+';
	}
	for (int i = 0; i < 6; i++)
		battlefield[y + i + 2][x] = '|';
	battlefield[y + 6][x] = '*';//下一格为发射大威力处
	battlefield[y + 4][x - 1] = '\\';  battlefield[y + 4][x + 1] = '/';
	battlefield[y + 2][x - 1] = '*'; battlefield[y + 2][x + 1] = '*';
	battlefield[y + 3][x + 2] = '/'; battlefield[y + 3][x - 2] = '\\';
	battlefield[y + 5][x + 1] = '\\'; battlefield[y + 5][x - 1] = '/';//子弹发射处
	battlefield[y + 3][x - 19] = '/'; battlefield[y + 3][x + 19] = '\\';
	battlefield[y + 3][x - 17] = '\\'; battlefield[y + 3][x + 17] = '/';
	battlefield[y + 4][x - 16] = '+'; battlefield[y + 4][x + 16] = '+';//子弹发射处
	battlefield[y + 4][x - 15] = '+'; battlefield[y + 4][x + 15] = '+';//子弹发射处
	battlefield[y + 4][x - 14] = '+'; battlefield[y + 4][x + 14] = '+';//子弹发射处
	battlefield[y + 3][x - 13] = '/'; battlefield[y + 3][x + 13] = '\\';
	battlefield[y + 2][x - 13] = '\\'; battlefield[y + 2][x + 13] = '/';
	battlefield[y + 4][x - 20] = '('; battlefield[y + 4][x + 20] = ')';
	battlefield[y + 4][x - 19] = ')'; battlefield[y + 4][x + 19] = '(';
	battlefield[y + 5][x - 19] = '\\'; battlefield[y + 5][x + 19] = '/';//子弹发射处
	battlefield[y + 1][x - 5] = '/';  battlefield[y + 1][x + 5] = '\\';
	battlefield[y + 2][x - 5] = '(';  battlefield[y + 2][x + 5] = ')';
	battlefield[y + 2][x - 4] = '_';  battlefield[y + 2][x + 4] = '_';
	battlefield[y + 2][x - 8] = ')';  battlefield[y + 2][x + 8] = '(';
	battlefield[y + 2][x - 10] = '(';  battlefield[y + 2][x + 10] = ')';
	battlefield[y + 3][x - 9] = 'V';  battlefield[y + 3][x + 9] = 'V';//子弹发射处
	Boss::shoot();
}
void Boss::shoot(){
	shoot_wait++;
	if (shoot_wait == 400)shoot_wait = 0;
	int x = getPosX();
	int y = getPosY();
	if (shoot_wait == 394){
		for (int i = 0; i < 10; i++){
			Bullet *b1 = new Bullet(x - 1, y + i + 6, Bullet::DOWN, 'O', 7);
			Bullet *b2 = new Bullet(x, y + i + 6, Bullet::DOWN, 'O', 7);
			Bullet *b3 = new Bullet(x + 1, y + i + 6, Bullet::DOWN, 'O', 7);
			bullets.push_front(b1);
			bullets.push_front(b2);
			bullets.push_front(b3);
		}
	}
	else {
		if (shoot_wait == 280)
			for (int i = 0; i < 6; i++){
			Bullet *b1 = new Bullet(x + 14, y + i + 4, Bullet::DOWN, '+', 6);
			Bullet *b2 = new Bullet(x + 15, y + i + 4, Bullet::DOWN, '=', 6);
			Bullet *b3 = new Bullet(x + 16, y + i + 4, Bullet::DOWN, '+', 6);
			Bullet *b4 = new Bullet(x - 14, y + i + 4, Bullet::DOWN, '+', 6);
			Bullet *b5 = new Bullet(x - 15, y + i + 4, Bullet::DOWN, '=', 6);
			Bullet *b6 = new Bullet(x - 16, y + i + 4, Bullet::DOWN, '+', 6);
			bullets.push_front(b1);
			bullets.push_front(b2);
			bullets.push_front(b3);
			bullets.push_front(b4);
			bullets.push_front(b5);
			bullets.push_front(b6);
			}
		if (shoot_wait % 159 == 0)
			for (int i = 0; i < 6; i++){
			Bullet *b1 = new Bullet(x - i + 14, y + i + 4, Bullet::LEFTDOWN, '*', 5);
			Bullet *b2 = new Bullet(x + 15, y + i + 4, Bullet::ARROUND1, '+', 6);
			Bullet *b3 = new Bullet(x + i + 16, y + i + 4, Bullet::RIGHTDOWN, '*', 5);
			Bullet *b4 = new Bullet(x + i - 14, y + i + 4, Bullet::RIGHTDOWN, '*', 5);
			Bullet *b5 = new Bullet(x - 15, y + i + 4, Bullet::ARROUND2, '+', 6);
			Bullet *b6 = new Bullet(x - i - 16, y + i + 4, Bullet::LEFTDOWN, '*', 5);
			bullets.push_front(b1);
			bullets.push_front(b2);
			bullets.push_front(b3);
			bullets.push_front(b4);
			bullets.push_front(b5);
			bullets.push_front(b6);
			}
		if (shoot_wait == 74)
			for (int i = 0; i < 3; i++){
			Bullet *b1 = new Bullet(x - 1 - i, y + i + 5, Bullet::LEFTDOWN, '/', 6);
			Bullet *b3 = new Bullet(x + 1 + i, y + i + 5, Bullet::RIGHTDOWN, '\\', 6);
			bullets.push_front(b1);
			bullets.push_front(b3);
			}
		if (shoot_wait % 167 == 0)
			for (int i = 0; i < 2; i++){
			Bullet *b1 = new Bullet(x - 19 + i, y + i + 5, Bullet::RIGHTDOWN, '\\', 6);
			Bullet *b3 = new Bullet(x + 19 - i, y + i + 5, Bullet::LEFTDOWN, '/', 6);
			bullets.push_front(b1);
			bullets.push_front(b3);
			}
		if (shoot_wait % 107 == 0)
			for (int i = 0; i < 2; i++){
			Bullet *b1 = new Bullet(x - 19 + i, y + i + 5, Bullet::ARROUND1, '*', 5);
			Bullet *b3 = new Bullet(x + 19 - i, y + i + 5, Bullet::ARROUND2, '*', 5);
			bullets.push_front(b1);
			bullets.push_front(b3);
			}
		if (shoot_wait % 67 == 0)
			for (int i = 0; i < 1; i++){
			Bullet *b1 = new Bullet(x - 9, y + i + 3, Bullet::DOWN, ':', 5);
			Bullet *b3 = new Bullet(x + 9, y + i + 3, Bullet::DOWN, ':', 5);
			bullets.push_front(b1);
			bullets.push_front(b3);
			}
		if (shoot_wait % 43 == 0)
			for (int i = 0; i < 2; i++){
			Bullet *b1 = new Bullet(x - 21, y + i + 4, Bullet::DOWN, ':', 5);
			Bullet *b3 = new Bullet(x + 21, y + i + 4, Bullet::DOWN, ':', 5);
			bullets.push_front(b1);
			bullets.push_front(b3);
			}
	}
}
int Boss::hurt(){
	int hurt = 0;
	int x = getPosX();
	int y = getPosY();
	for (list<Bullet*>::iterator iter = bullets.begin(); iter != bullets.end(); ++iter){
		hurt += (*iter)->hurt(x, y);
	}
	hurt += Enemy::hurt0(x, y);
	return hurt;
}
void Boss::reduce_life(Myplane &p){
	if (alive >= 0){
		int x = getPosX();
		int y = getPosY();
		alive -= p.hurt(x, y);
		for (int i = 1; i < 13; i++){
			alive -= p.hurt(x - i, y);
			alive -= p.hurt(x + i, y);
		}
		for (int i = 3; i <= 7; i++)
			alive -= p.hurt(x, y + i);
		alive -= p.hurt(x+2, y + 3);
		alive -= p.hurt(x-2, y + 3);
		alive -= p.hurt(x-1, y + 4);
		alive -= p.hurt(x+1, y + 4);
		alive -= p.hurt(x-1, y + 5);
		alive -= p.hurt(x+1, y + 5);
		for (int i = 1; i < 18; i++){
			alive -= p.hurt(x - i, y + 2);
			alive -= p.hurt(x + i, y + 2);
		}
		for (int i = 13; i <= 20; i++){
			alive -= p.hurt(x - i, y + 2);
			alive -= p.hurt(x + i, y + 2);
		}
	}
}