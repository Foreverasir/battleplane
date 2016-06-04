#pragma once

const int WIDTH = 48;
const int HEIGHT = 32;
extern char battlefield[HEIGHT][WIDTH];
class Myplane;
class Game_run;
class Bullet;
class Magic;
enum ENEMYKIND{ SMALL1, SMALL2, SMALL3, SMALL4, MID1, MID2, MID3, BIG1, BOSS };
enum GOODKIND{ LIFE, BLOODE, BULLET1, BULLET2, ZHADAN, MAGIC };
enum KEYBOARDSTATE{ RIGHT, LEFT, DOWN, UP, FIRE, RESTART, PAUSE, BOMB, MAGIC1, MAGIC2, MAGIC3, MAGIC4, MAGIC5, EXIT };