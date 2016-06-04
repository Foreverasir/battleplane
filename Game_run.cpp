#include <conio.h>
#include<list>
#include "Game_run.h"
#include "Display.h"
using namespace std;

char battlefield[HEIGHT][WIDTH];

int Game_run::time_wait = 21;

Game_run::Game_run():player(24,16){
	enemy_born = 0;
	for (int i = 0; i < 14; i++)
		states[i] = 1;
}
Game_run::~Game_run(){
	for (list<Enemy*>::iterator iter = enemy_list.begin(); iter != enemy_list.end();){
		delete (*iter);
		enemy_list.erase(iter++);
	}
}
void  Game_run::check_keyboard_input(){
	states[UP] = GetAsyncKeyState('W');
	states[DOWN] = GetAsyncKeyState('S');
	states[LEFT] = GetAsyncKeyState('A');
	states[RIGHT] = GetAsyncKeyState('D');
	states[FIRE] = GetAsyncKeyState('J');
	states[RESTART] = GetAsyncKeyState('R');
	states[PAUSE] = GetAsyncKeyState(' ');
	states[BOMB] = GetAsyncKeyState('K');
	states[MAGIC1] = GetAsyncKeyState('L');
	states[MAGIC2] = GetAsyncKeyState('U');
	states[MAGIC3] = GetAsyncKeyState('I');
	states[MAGIC4] = GetAsyncKeyState('O');
	states[MAGIC5] = GetAsyncKeyState('P');
	SHORT exi = GetAsyncKeyState('T');
	if (exi == 1){
		system("cls");
		game_interrupt();
		system("pause");
		exit(0);
	}
}
void Game_run::update(){
	for (list<Enemy*>::iterator iter = enemy_list.begin(); iter != enemy_list.end(); ++iter){
		(*iter)->update();
	}
	update_field(player.score, player.alive, player.life, player.bomb, player.m1, player.m2, player.m3, player.m4, player.m5);
}
void Game_run::update_2(Boss *b){
	if(b->still_alive())b->update();
	for (list<Enemy*>::iterator iter = enemy_list.begin(); iter != enemy_list.end(); ++iter){
		(*iter)->update();
	}
	update_field(player.score, player.alive, player.life, player.bomb, player.m1, player.m2, player.m3, player.m4, player.m5);
}
void Game_run::add_enemy(){
	int sx = rand() % 48;
	int k = rand() % 8;
	enemy_born++;
	if (enemy_born == time_wait){
		Enemy *p = new Enemy(sx, 0,k);
		if (p == NULL){ cerr << "Space error!\n"; exit(1); }
		enemy_list.push_front(p);
		enemy_born = 0;
	}
}
Boss* Game_run::add_boss(){
	Boss *b = new Boss();
	if (b == NULL){ cerr << "Space error!\n"; exit(1); }
	enemy_list.push_front(b);
	return b;
}
void Game_run::move_clear_enemy(){//同时移动并清理出界
	for (list<Enemy*>::iterator iter = enemy_list.begin(); iter != enemy_list.end();){
		(*iter)->move(rand() % 3,player);
		if ((*iter)->x<0 || (*iter)->x>=WIDTH || (*iter)->y>=HEIGHT){
			delete (*iter);
			enemy_list.erase(iter++);
		}
		else
			++iter;
	}
}
bool Game_run::check_crash(){
	for (list<Enemy*>::iterator iter = enemy_list.begin(); iter != enemy_list.end();){
		(*iter)->reduce_life(player);
		player.reduce(*iter);
		for (list<Bullet*>::iterator iterb = (*iter)->get_bullets().begin(); iterb != (*iter)->get_bullets().end();iterb++){//子弹碰子弹
			if (player.hurt((*iterb)->getPosX(), (*iterb)->getPosY()) > 0){//也包含player碰到子弹
				if ((*iterb)->kind != 7)
					(*iterb)->kill();
			}
		}
		(*iter)->clear_bullet();
		player.clear_bullet();
		if ((*iter)->still_alive() == false){
			player.gain_score((*iter)->give_score());
			if ((*iter)->give_score() == 10000){ 
				delete (*iter);
				enemy_list.erase(iter++);
				return true; 
			}
			delete (*iter);
			enemy_list.erase(iter++);
		}
		else
			++iter;
	}
	return false;
}
bool Game_run::check_life(){
	if (player.alive <= 0 && player.life <= 0){
		Sleep(1000);
		system("cls");
		game_over(player.score);
		system("pause>nul");
		return false;
	}
	if (player.alive <= 0 && player.life > 0){
		Sleep(1000);
		if (player.next_life()){
			for (list<Enemy*>::iterator iter = enemy_list.begin(); iter != enemy_list.end();){
				for (list<Bullet*>::iterator iterb = (*iter)->get_bullets().begin(); iterb != (*iter)->get_bullets().end(); iterb++)
					(*iterb)->kill();
				if ((*iter)->y > 20){
					delete (*iter);
					enemy_list.erase(iter++);
				}
				else iter++;
			}
		}
		player.x = 25;
		player.y = 31;
		update_field(player.score, player.alive, player.life, player.bomb, player.m1, player.m2, player.m3, player.m4, player.m5);
	}
	return true;
}
void Game_run::check_bomb(){
	short b = 1;
	short lines = 9;
	int y = player.y;
	if (player.alive > 0) b = GetAsyncKeyState('K');
	if (b < 0 && player.bomb > 0){
		player.Bomb();
		for (; lines > 1; lines--){
			Bullet *b;
			for (int i = ((player.x - 4) >= 0 ? (player.x - 4) : 0); i < ((player.x + 4) < WIDTH ? (player.x + 5) : WIDTH); i++){
				if (y > 0){
					b = new Bullet(i, y, Bullet::UP, 'O', 2);
					player.bullets.push_front(b);
				}
			}
			y--;
		}
	}
}
void Game_run::check_magic(Magic &m){
	short m1 = 1, m2 = 1, m3 = 1, m4 = 1, m5 = 1;
	if (player.alive > 0){
		m1 = GetAsyncKeyState('L');
		m2 = GetAsyncKeyState('U');
		m3 = GetAsyncKeyState('I');
		m4 = GetAsyncKeyState('O');
		m5 = GetAsyncKeyState('P');
	}
	if (m1 < 0 && player.m1>0){
		m.m1(player);
		player.m1--;
	}
	else if (m2 < 0 && player.m2>0){
		m.m2(player);
		player.m2--;
	}
	else if (m3 < 0 && player.m3>0){
		m.m3(player);
		player.m3--;
	}
	else if (m4 < 0 && player.m4>0){
		m.m4(player);
		player.m4--;
	}
	else if (m5 < 0 && player.m5>0){
		m.m5(player);
		player.m5--;
	}
}
void Game_run::add_good(){
	if (player.score % 1000 == 0 && player.score != 0){
		Good *gd = new Good();
		good_list.push_front(gd);
		good_list.push_front(gd);
		good_list.push_front(gd);
		good_list.push_front(gd);
		player.score += 50;
	}
	if (player.still_alive() && rand() % 100 == 0 ){
		Good *gd = new Good();
		good_list.push_front(gd);
	}
	else return;
}
void Game_run::move_clear_good(){
	for (list<Good*>::iterator iter = good_list.begin(); iter != good_list.end();){
		if ((*iter)->increase(player)){
			delete (*iter);
			good_list.erase(iter++);
		}
		else iter++;
	}
	for (list<Good*> ::iterator iter = good_list.begin(); iter != good_list.end();){
		(*iter)->move();
		if ((*iter)->increase(player)){
			delete (*iter);
			good_list.erase(iter++);
		}
		else{
			(*iter)->update();
			iter++;
		}
	}
}
void Game_run::pause(){
	if ((states[PAUSE]) < 0)
		system("pause>nul");
}
int Game_run::game_run(){
	system("mode con cols=80 lines=50");
	const_display();
	short time_count = 0;
	Magic magic;
	for (int i = 0; i < HEIGHT; i++)
		for (int j = 0; j < WIDTH; j++)
			battlefield[i][j] = ' ';
	update();
	while (1){
		time_count++;
		if (time_count == 400 && time_wait >= 7){
			time_count = 0;
			time_wait--;
		}
		for (int i = 0; i < HEIGHT; i++)
			for (int j = 0; j < WIDTH; j++)
				battlefield[i][j] = ' ';
		if(check_life()==0)return 0;
		check_bomb();
		check_magic(magic);
		if (time_wait == 7 && time_count >= 300){
			time_count = 0;
			Boss* b = add_boss();
			bool flag = boss_run(b);
			if (flag == true)return 1;
		}
		else add_enemy();
		add_good();
		check_keyboard_input();
		pause();
		if ((states[FIRE]) < 0 && player.still_alive()) player.shoot();//射击
		if (player.still_alive()) player.move(states);//移动
		player.move_bullet();
		check_crash();//这时候不先调用一次的话，子弹会有穿出敌机的可能，故须两次，原因是下面的函数使得敌机移动，判定在一瞬间可能缺失
		move_clear_good();
		move_clear_enemy();
		check_crash();
		player.update();
		update();
	}
}
void Game_run::boss_die(){
	system("cls");
	update();
	const_display();
	Sleep(500);
	system("cls");
	update();
	const_display();
	Sleep(500);
	system("cls");
	update();
	const_display();
	Sleep(2500);
	system("cls");
	game_win(player.score);
	system("pause>nul");
}
bool Game_run::boss_run(Boss *b){
	Magic magic;
	short flag = 0;
	update();
	while (1){
		for (int i = 0; i < HEIGHT; i++)
			for (int j = 0; j < WIDTH; j++)
				battlefield[i][j] = ' ';
		if (check_life() == 0)return 0;
		check_bomb();
		check_magic(magic);
		if (rand() % 10 == 0)add_good();
		check_keyboard_input();
		pause();
		if ((states[FIRE]) < 0 && player.still_alive()) player.shoot();
		if (player.still_alive()) player.move(states);
		player.move_bullet();
		if (check_crash() == true)flag = 1;
		move_clear_good();
		move_clear_enemy();
		if (check_crash() == true)flag = 1;
		player.update();
		update_2(b);
		if (flag >= 1)flag++;
		if (flag >= 10){ boss_die(); return true; }
	}
	return false;
}