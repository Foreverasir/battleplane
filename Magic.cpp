#include "Magic.h"
extern char battlefield[HEIGHT][WIDTH];

void Magic::m1(Myplane &p){
	if (p.y > 10)p.y -= 10;
}
void Magic::m2(Myplane &p){
	Bullet *b;
	for (int i = p.x - 1; i <= p.x + 1; i++){
		b = new Bullet(i, p.y, Bullet::UP, '\4', 2);
		p.bullets.push_front(b);
		b = new Bullet(i, p.y - 1, Bullet::UP, '\4', 2);
		p.bullets.push_front(b);
		b = new Bullet(i, p.y - 2, Bullet::UP, '\4', 2);
		p.bullets.push_front(b);
	}
	for (int i = p.x - 1; i <= p.x + 1; i++){
		b = new Bullet(i, p.y, Bullet::DOWN, '\4', 2);
		p.bullets.push_front(b);
		b = new Bullet(i, p.y + 1, Bullet::DOWN, '\4', 2);
		p.bullets.push_front(b);
		b = new Bullet(i, p.y + 2, Bullet::DOWN, '\4', 2);
		p.bullets.push_front(b);
	}
	for (int i = p.y - 1; i <= p.y + 1; i++){
		b = new Bullet(p.x - 1, i, Bullet::LEFT, '\4', 2);
		p.bullets.push_front(b);
		b = new Bullet(p.x - 2, i, Bullet::LEFT, '\4', 2);
		p.bullets.push_front(b);
		b = new Bullet(p.x, i, Bullet::LEFT, '\4', 2);
		p.bullets.push_front(b);
	}
	for (int i = p.y - 1; i <= p.y + 1; i++){
		b = new Bullet(p.x + 2, i, Bullet::RIGHT, '\4', 2);
		p.bullets.push_front(b);
		b = new Bullet(p.x + 1, i, Bullet::RIGHT, '\4', 2);
		p.bullets.push_front(b);
		b = new Bullet(p.x, i, Bullet::RIGHT, '\4', 2);
		p.bullets.push_front(b);
	}
	for (int i = p.y + 1; i < p.y + 3; i++){
		for (int j = p.x + 1; j < p.x + 3; j++){
			b = new Bullet(j, i, Bullet::RIGHTDOWN, '\4', 2);
			p.bullets.push_front(b);
		}
	}
	for (int i = p.y + 1; i < p.y + 3; i++){
		for (int j = p.x - 3; j < p.x -1; j++){
			b = new Bullet(j, i, Bullet::LEFTDOWN, '\4', 2);
			p.bullets.push_front(b);
		}
	}
	for (int i = p.y - 3; i < p.y - 1; i++){
		for (int j = p.x - 3; j < p.x - 1; j++){
			b = new Bullet(j, i, Bullet::LEFTUP, '\4', 2);
			p.bullets.push_front(b);
		}
	}
	for (int i = p.y - 3; i < p.y - 1; i++){
		for (int j = p.x + 1; j < p.x + 3; j++){
			b = new Bullet(j, i, Bullet::RIGHTUP, '\4', 2);
			p.bullets.push_front(b);
		}
	}
}
void Magic::m3(Myplane &p){
	Bullet *b;
	for (int i = 0; i <= 42; i += 6){
		for (int j = 31; j > 20; j -= 2){
			b = new Bullet(i + 1, j, Bullet::SHADOW, '$', 7);
			p.bullets.push_front(b);
		}
	}
	for (int i = 3; i <= 45; i += 6){
		for (int j = 30; j > 19; j -= 2){
			b = new Bullet(i + 1, j, Bullet::SHADOW, '$', 7);
			p.bullets.push_front(b);
		}
	}
}
void Magic::m4(Myplane &p){
	Bullet *b;
	for (int j = 31; j > 19; j--){
		for (int i = 0; i < 8; i++){
			b = new Bullet(i, j, Bullet::UP, '\4', 3);
			p.bullets.push_front(b);
		}
		for (int i = 20; i < 28; i++){
			b = new Bullet(i, j, Bullet::UP, '\4', 3);
			p.bullets.push_front(b);
		}
		for (int i = 40; i < 48; i++){
			b = new Bullet(i, j, Bullet::UP, '\4', 3);
			p.bullets.push_front(b);
		}
	}
	for (int j = 23; j > 11; j--){
		for (int i = 10; i < 18; i++){
			b = new Bullet(i, j, Bullet::UP, '\4', 3);
			p.bullets.push_front(b);
		}
		for (int i = 30; i < 38; i++){
			b = new Bullet(i, j, Bullet::UP, '\4', 3);
			p.bullets.push_front(b);
		}
	}
}
void Magic::m5(Myplane &p){
	int k = 23;
	for (int j = 31; j > 14;j--){
		Bullet *b;
		for (int i = k; i < WIDTH-k; i++){
			b = new Bullet(i, j, Bullet::UP, '\3', 8);
			p.bullets.push_front(b);
		}
		if (j<=17)k++;
		else if (k>1)k -= 2;
	}
	k = 4;
	for (int j = 14; j > 9; j--){
		Bullet *b;
		for (int i = k; i <= 25 - k; i++){
			b = new Bullet(i, j, Bullet::UP, '\3', 8);
			p.bullets.push_front(b);
		}
		for (int i = k + 22; i < 48 - k; i++){
			b = new Bullet(i, j, Bullet::UP, '\3', 8);
			p.bullets.push_front(b);
		}
		k += 3;
	}
}