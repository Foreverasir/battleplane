#include"Myplane.h"

extern char battlefield[HEIGHT][WIDTH];
extern enum BKIND{ PONE, PTWO, PTHREE, PFOUR, EONE, ETWO, ETHREE, EFOUR, PLOVE };
Myplane::Myplane(int sx,int sy){
	x = sx;y = sy;
	alive = 400;life = 3;score = 0;
	bomb = 10; bkind = 0; blines = 1;
	m1 = 20; m2 = 10; m3 = 8; m4 = 5; m5 = 3;
}
void Myplane::move(SHORT *stas){
	if (alive  > 0){
		if (stas[RIGHT] <0)
			(x <  WIDTH - 1) ? ++x : x = x;
		if (stas[UP] <0)
			y > 0 ? y-- : y = y;
		if (stas[LEFT] <0)
			x > 0 ? x-- : x = x;
		if (stas[DOWN] <0)
			(y < HEIGHT - 1) ? y++ : y = y;
	}
}
void Myplane::update(){
	for (list<Bullet*>::iterator iter = bullets.begin(); iter != bullets.end(); ++iter){//iterator begin()返回首元素的迭代器指针iterator end()返回尾元素之后位置的迭代器指针
		(*iter)->updata();
	}
	if (alive > 0){
		if (x - 1 >=0)
			battlefield[y][x-1] = '>';
		if (x + 1 < WIDTH)
			battlefield[y][x+1] = '<';
		battlefield[y][x] = '$';
	}
	else{
		if (x - 1 >0)
			battlefield[y][x - 1] = 'X';
		if (x + 1 < WIDTH)
			battlefield[y][x + 1] = 'X';
		battlefield[y][x] = 'X';
	}
}
void Myplane::add_magic(int i){
	switch (i){
	case 0:m1++; break;
	case 1:m1++; break;
	case 2:m1++; break;
	case 3:m2++; break;
	case 4:m2++; break;
	case 5:m3++; break;
	case 6:m3++; break;
	case 7:m4++; break;
	case 8:m5++; break;
	default:return;
	}
}
void Myplane::shoot(){
	char ch = '*';
	switch (bkind){
	case 0:break;
	case 1:ch = '\4'; break;
	case 2:ch = '!'; break;
	case 3:ch = '8'; break;
	case 8:ch = '\3'; break;
	}
	if (blines == 7){
		Bullet* b1 = new Bullet(x, y, Bullet::UP, ch, bkind);
		Bullet* b2 = new Bullet(x - 1, y, Bullet::UP, ch, bkind);
		Bullet* b3 = new Bullet(x + 1, y, Bullet::UP, ch, bkind);
		Bullet* b4 = new Bullet(x - 2, y, Bullet::LEFTUP, ch, bkind);
		Bullet* b5 = new Bullet(x + 2, y, Bullet::RIGHTUP, ch, bkind);
		Bullet* b6 = new Bullet(x - 2, y + 1, Bullet::LEFTUP, ch, bkind);
		Bullet* b7 = new Bullet(x + 2, y + 1, Bullet::RIGHTUP, ch, bkind);
		bullets.push_front(b1);
		bullets.push_front(b2);
		bullets.push_front(b3);
		bullets.push_front(b4);
		bullets.push_front(b5);
		bullets.push_front(b6);
		bullets.push_front(b7);
	}
	else {
		if (blines == 5){
			Bullet* b1 = new Bullet(x, y, Bullet::UP, ch, bkind);
			Bullet* b2 = new Bullet(x - 1, y, Bullet::UP, ch, bkind);
			Bullet* b3 = new Bullet(x + 1, y, Bullet::UP, ch, bkind);
			Bullet* b4 = new Bullet(x - 2, y, Bullet::LEFTUP, ch, bkind);
			Bullet* b5 = new Bullet(x + 2, y, Bullet::RIGHTUP, ch, bkind);
			bullets.push_front(b1);
			bullets.push_front(b2);
			bullets.push_front(b3);
			bullets.push_front(b4);
			bullets.push_front(b5);
		}
		else {
			if (blines == 3){
				Bullet* b1 = new Bullet(x, y, Bullet::UP, ch, bkind);
				Bullet* b2 = new Bullet(x - 1, y, Bullet::UP, ch, bkind);
				Bullet* b3 = new Bullet(x + 1, y, Bullet::UP, ch, bkind);
				bullets.push_front(b1);
				bullets.push_front(b2);
				bullets.push_front(b3);
			}
			else{
				Bullet *b = new Bullet(x, y, Bullet::UP, ch, bkind);
				bullets.push_front(b);//list元素首元素子弹前添加一个子弹
			}
		}
	}
}
void Myplane::move_bullet(){
	for (list<Bullet*>::iterator iter = bullets.begin(); iter != bullets.end();){//子弹移动
		(*iter)->move();
		if ((*iter)->inscreen() == false){
			delete (*iter);
			bullets.erase(iter++);
		}
		else
			++iter;
	}
}
void Myplane::clear_bullet(){//子弹碰撞
	for (list<Bullet*>::iterator iter = bullets.begin(); iter != bullets.end();){
		if ((*iter)->get_alive() == false){
			delete (*iter);
			bullets.erase(iter++);
		}
		else
			++iter;
	}
}
bool Myplane::next_life(){
	if (life > 0){
		life--;
		alive = 200;
		blines = 1; bkind = 0;
		if (score > 15000){ blines = 5; bkind = 2; }
		else if (score > 8000){ blines = 3; bkind = 2; }
		else if (score > 3000){ blines = 3; bkind = 1; }
		return true;
	}
	else
		return false;
}
void Myplane::reduce(Enemy *e){
	if (alive >0){
		for (list<Bullet*>::iterator iter = bullets.begin(); iter != bullets.end(); ++iter){
			if (e->hurt((*iter)->getPosX(), (*iter)->getPosY()) > 0)//子弹碰撞
				(*iter)->kill();
		}
		int dec = 0;
		dec += e->hurt(x, y);
		dec += e->hurt(x - 1, y);
		dec += e->hurt(x + 1, y);
		if (dec > 0)printf("\a");
		if (dec > 200){ if (blines >= 5)blines -= 2; if (bkind >= 1)bkind--; }//削弱
		alive -= dec;
		if (alive < 0)	alive = 0;
	}
}
int Myplane::hurt(int x, int y){//在某一位置的伤害
	int hurt = 0;
	for (list<Bullet*>::iterator iter = bullets.begin(); iter != bullets.end(); ++iter){
		hurt += ((*iter)->hurt(x, y));
	}
	if (alive > 0 && (x == this->x && y == this->y) || ((x - 1) == this->x && y == this->y) || ((x + 1) == this->x && y == this->y))
		hurt += 100;//撞机敌人造成伤害
	return hurt;
}
void Myplane::Bomb(){
	if (bomb >0)bomb--;
}