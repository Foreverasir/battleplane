#include "Enemy.h"

Enemy::Enemy(int sx, int sy, short kind){
	x = sx; y = sy; speed = 0; move_wait = 0;
	ekind = (ENEMYKIND)kind;
	switch (kind){
	case 0:alive = 30; bkind = 4; break;
	case 1:alive = 50; bkind = 4; speed = 2; break;
	case 2:alive = 60; bkind = 5; break;
	case 3:alive = 100; bkind = 5; break;
	case 4:alive = 360; bkind = 6; speed = 3; break;
	case 5:alive = 200; bkind = 6; break;
	case 6:alive = 400; bkind = 7; break;
	case 7:alive = 600; bkind = 7; speed = 5; break;
	case 8:alive = 50000; bkind = 7; speed = 4; break;
	default:break;
	}
}
int Enemy::give_score(){
	switch (ekind){
	case 0:return 20;
	case 1:return 30;
	case 2:return 70;
	case 3:return 60;
	case 4:return 100;
	case 5:return 150;
	case 6:return 300;
	case 7:return 400;
	case 8:return 10000;
	default:return 0;
	}
}
void Enemy::clever_move(Myplane &p){
	bool nextpos[3] = { false };
	for (list<Bullet*>::iterator iter = p.get_bullets().begin(); iter != p.get_bullets().end(); ++iter){//躲避子弹的同时靠近玩家
		if (x == (*iter)->getPosX() && y == (*iter)->getPosY())
			nextpos[1] = true;
		if (x - 1 == (*iter)->getPosX() && y == (*iter)->getPosY())
			nextpos[0] = true;
		if (x + 1 == (*iter)->getPosX() && y == (*iter)->getPosY())
			nextpos[2] = true;
	}
	if (x > p.getPosX() && (!(nextpos[0]) || y == p.getPosY()))
		x--;
	else if (x < p.getPosX() && (!(nextpos[2]) || y == p.getPosY()))
		x++;
	else if (x == p.getPosX() && nextpos[1]){
		if (!(nextpos[0]))
			x--;//优先向左移
		else if (!nextpos[2])
			x++;
	}
}
void Enemy::move(short count, Myplane &p){
	switch (ekind){
	case 0:if (count == 2)y++; break;
	case 1:
		if (count == 0)y++; break;
	case 2:
		y++;
		clever_move(p);
		break;
	case 3:
		if (count == 1)y++;
		break;
	case 4:
		if (move_wait == speed){ y++; move_wait = 0; }
		else move_wait++;
		break;
	case 5:
		if (count == 1){
			clever_move(p);
			y++;
		}
		break;
	case 6:
		if (count==2){ clever_move(p); y++; }
		break;
	case 7:
		if (move_wait == speed){ y++; move_wait = 0; }
		else move_wait++;
		break;
	case 8:
		if (move_wait == speed && (x < 26) && (x>21)){
			if (count == 1 && x < 25)x++;
			else if (count == 0 && x > 22)x--;
			move_wait = 0;
		}
		else move_wait++;
	default:break;
	}
	return;
}
void Enemy::shoot(){
	char ch = '.';
	switch (ekind){
	case 0:bkind = 4; break;//SMALL1
	case 1:bkind = 4; ch = ':'; break;//SMALL2
	case 2:bkind = 5; ch = '|'; break;//SMALL3
	case 3:bkind = 5; ch = '|'; break;//SMALL4
	case 4:bkind = 6; ch = '='; break;//MID1
	case 5:bkind = 6; ch = '+'; break;//MID2
	case 6:bkind = 7; ch = '#'; break;//MID3
	case 7:bkind = 7; ch = '@'; break;//BIG1
	default:break;
	}
	switch (ekind){
	case 0:
		if (rand() % 8 == 0){
			Bullet *b = new Bullet(x, y, Bullet::DOWN, ch, bkind);
			bullets.push_front(b);
		}
		break;
	case 1:
		if (rand() % 8 == 1){
			Bullet* b1 = new Bullet(x + 1, y, Bullet::DOWN, ch, bkind);
			Bullet* b2 = new Bullet(x - 1, y, Bullet::DOWN, ch, bkind);
			bullets.push_front(b1);
			bullets.push_front(b2);
		}
		break;
	case 2:
		
		break;
	case 3:
		if (rand() % 8 == 3){
			Bullet* b1 = new Bullet(x - 1, y, Bullet::LEFTDOWN, ch, bkind);
			bullets.push_front(b1);
		}
		else if (rand() % 8 == 1){
			Bullet* b2 = new Bullet(x + 1, y, Bullet::RIGHTDOWN, ch, bkind);
			bullets.push_front(b2);
		}
		break;
	case 4:
		if (rand() % 8 == 2){
			Bullet* b1 = new Bullet(x - 1, y, Bullet::ARROUND2, ch, bkind);
			Bullet* b2 = new Bullet(x + 1, y, Bullet::ARROUND1, ch, bkind);
			bullets.push_front(b1);
			bullets.push_front(b2);
		}
		break;
	case 5:
		if (rand() % 8 == 4){
			Bullet *b = new Bullet(x, y, Bullet::DOWN, ch, bkind);
			bullets.push_front(b);
		}
		else if (rand() % 8 == 3){
			Bullet* b1 = new Bullet(x + 1, y, Bullet::LEFTDOWN, ch, bkind);
			Bullet* b2 = new Bullet(x - 1, y, Bullet::RIGHTDOWN, ch, bkind);
			bullets.push_front(b1);
			bullets.push_front(b2);
		}
		break;
	case 6:
		if (rand() % 8 == 5){
			Bullet* b1 = new Bullet(x + 1, y, Bullet::DOWN, ch, bkind);
			Bullet* b2 = new Bullet(x - 1, y, Bullet::DOWN, ch, bkind);
			bullets.push_front(b1);
			bullets.push_front(b2);
		}
		break;
	case 7:
		if (rand() % 8 == 6){
			Bullet *b = new Bullet(x, y, Bullet::DOWN, ch, bkind);
			bullets.push_front(b);
		}
		else if (rand() % 8 == 7){
			Bullet* b1 = new Bullet(x + 1, y, Bullet::LEFTDOWN, ch, bkind);
			Bullet* b2 = new Bullet(x - 1, y, Bullet::RIGHTDOWN, ch, bkind);
			bullets.push_front(b1);
			bullets.push_front(b2);
		}
		break;
	default:break;
	}

}
void Enemy::update(){
	for (list<Bullet*>::iterator iter = bullets.begin(); iter != bullets.end();){//子弹移动
		(*iter)->move();
		if ((*iter)->inscreen() == false){
			delete (*iter);
			bullets.erase(iter++);
		}
		else
			++iter;
	}
	for (list<Bullet*>::iterator iter = bullets.begin(); iter != bullets.end(); ++iter){
		(*iter)->updata();
	}
	if (alive > 0){
		switch (ekind){
		case 0:battlefield[y][x] = 'W'; break;
		case 1:battlefield[y][x] = 'U'; break;
		case 2:battlefield[y][x] = 'A'; break;
		case 3:battlefield[y][x] = 'M'; break;
		case 4:
			battlefield[y][x] = 'W';
			if (x - 1 >0)
				battlefield[y][x - 1] = 'M';
			if (x + 1 < WIDTH)
				battlefield[y][x + 1] = 'M'; 
			break;
		case 5:battlefield[y][x] = 'H';
			if (x - 1 >0)
				battlefield[y][x - 1] = 'O';
			if (x + 1 < WIDTH)
				battlefield[y][x + 1] = 'O';
			break;
		case 6:battlefield[y][x] = 'V';
			if (x - 1 >0)
				battlefield[y][x - 1] = ']';
			if (x + 1 < WIDTH)
				battlefield[y][x + 1] = '[';
			break;
		case 7:
			battlefield[y][x] = 'U';
			if (x - 2 >0)
				battlefield[y][x - 2] = '>';
			if (x + 2 < WIDTH)
				battlefield[y][x + 2] = '<';
			if (x - 1 > 0){
				battlefield[y][x - 1] = 'B';
				if (y - 1 > 0){ battlefield[y - 1][x - 1] = '+'; battlefield[y - 1][x - 1] = '+'; }
				if (y + 1 < HEIGHT){ battlefield[y + 1][x - 1] = '+'; battlefield[y + 1][x - 1] = '+'; }
			}
			if (x + 1 < WIDTH){
				battlefield[y][x + 1] = 'G';
				if (y - 1 > 0){ battlefield[y - 1][x + 1] = '+'; battlefield[y - 1][x + 1] = '+'; }
				if (y + 1 < HEIGHT){ battlefield[y + 1][x + 1] = '+'; battlefield[y + 1][x + 1] = '+'; }
			}
			break;
		default:break;
		}
		shoot();
	}
}
void Enemy::clear_bullet(){
	for (list<Bullet*>::iterator iter = bullets.begin(); iter != bullets.end();){
		if ((*iter)->get_alive() == false){
			delete (*iter);
			bullets.erase(iter++);
		}
		else
			++iter;
	}
}
void Enemy::reduce_life(Myplane &p){
	if (alive > 0){
		alive -= p.hurt(x, y);
		if (ekind == 4 || ekind == 5 || ekind == 6 || ekind == 7){
			alive -= p.hurt(x-1, y)/2;
			alive -= p.hurt(x+1, y)/2;
		}
		if (ekind == 7){
			alive -= p.hurt(x - 1, y+1)/2;
			alive -= p.hurt(x + 1, y+1)/2;
			alive -= p.hurt(x - 2, y)/2;
			alive -= p.hurt(x + 2, y)/2;
		}
	}
}
int Enemy::hurt(int x, int y){//对某点的伤害
	int hurt = 0;
	for (list<Bullet*>::iterator iter = bullets.begin(); iter != bullets.end(); ++iter){
		hurt += (*iter)->hurt(x, y);
	}
	hurt += Enemy::hurt0(x, y);
	return hurt;
}
int Enemy::hurt0(int x, int y){//撞机,人肉炸弹
	if (alive > 0){
		switch (ekind){
		case 0:if (x == this->x && y == this->y)return 25; break;
		case 1:if (x == this->x && y == this->y)return 35; break;
		case 2:if (x == this->x && y == this->y)return 50; break;
		case 3:if (x == this->x && y == this->y)return 60; break;
		case 4:
			if ((x == this->x && y == this->y) || ((x - 1) == this->x && y == this->y) || ((x + 1) == this->x && y == this->y))
				return 80; break;
		case 5:
			if ((x == this->x && y == this->y) || ((x - 1) == this->x && y == this->y) || ((x + 1) == this->x && y == this->y))
				return 100; break;
		case 6:
			if ((x == this->x && y == this->y) || ((x - 1) == this->x && y == this->y) || ((x + 1) == this->x && y == this->y))
				return 150; break;
		case 7:
			if ((x == this->x && y == this->y) || ((x - 1) == this->x && y == this->y) || ((x + 1) == this->x && y == this->y))
				return 200;
			if (((x - 2) == this->x && y == this->y) || ((x + 2) == this->x && y == this->y) || ((x - 1) == this->x && (y + 1) == this->y) || ((x + 1) == this->x && (y + 1) == this->y))
				return 100;
			break;
		case 8:
			if (y <= 4 && x<(this->x + 20) && x>(this->x - 20))return 1000;
		default:return 0;
		}
	}
	return 0;
}