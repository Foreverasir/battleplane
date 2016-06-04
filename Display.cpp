#include <iostream>
#include <windows.h>
#include <conio.h>	//getch()
#include <stdlib.h> //system函数所需头文件
#include "SomeConst.h"
#define stoptimelong 800
using namespace std;

//隐藏光标
void HideCursor(){
	CONSOLE_CURSOR_INFO cursor_info = { 1, 0 };
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
}
//跳到屏幕指定坐标，此处封装一体
void gotoxy(int x, int y){
	CONSOLE_SCREEN_BUFFER_INFO  csbiInfo;
	HANDLE  hConsoleOut = GetStdHandle(STD_OUTPUT_HANDLE);
	GetConsoleScreenBufferInfo(hConsoleOut, &csbiInfo);
	csbiInfo.dwCursorPosition.X = x;
	csbiInfo.dwCursorPosition.Y = y;
	SetConsoleCursorPosition(hConsoleOut, csbiInfo.dwCursorPosition);
}
void Start_display(){//调用控制台颜色管理命令，可以改变屏幕和字体的颜色
	system("cls");
	gotoxy(18, 5);
	system("color 0E");
	printf("╟	    公元2015年，");
	Sleep(stoptimelong);
	printf("人类文明遭遇危机。");
	Sleep(stoptimelong);
	gotoxy(25, 7);
	printf("邪恶的巴格星人向地球发起了疯狂的进攻。");
	Sleep(stoptimelong);
	gotoxy(27, 9);
	printf("作为人类文明先锋的程序猿首当其冲。");
	Sleep(stoptimelong);
	gotoxy(31, 11);
	printf("人类终于想起来了被巨人。。");
	Sleep(stoptimelong);
	gotoxy(29, 13);
	printf("啊不对，被BUG所支配的黑暗岁月。");
	Sleep(stoptimelong);
	gotoxy(25, 15);
	printf("终于，伟大的社会主义程序猿战士挺身而出");
	Sleep(stoptimelong);
	gotoxy(37, 17);
	printf("泽");Sleep(500);
	printf("凡");Sleep(500);
	printf("·");Sleep(500);
	printf("兰");Sleep(500);
	printf("博");Sleep(500);
	printf("！");Sleep(500);
	printf("！");Sleep(500);
	gotoxy(22, 19);
	printf("他带着全人类的希望，驾驶无产阶级一号冲向平流层。");
	Sleep(stoptimelong);
	gotoxy(34, 21);
	printf("		 Fight  or  Die!!	╢");
	cout << endl << endl;
	printf("				  ·请按任意键开始·\n");
	_getch();
}
int drawMenu(){
	system("mode con cols=90 lines=50");//改变控制台大小
	gotoxy(0, 1);
	printf("=========================================================================================");
	gotoxy(33, 2);
	cout << "<$  進 擊  の  B U G  $>" << endl;
	gotoxy(0, 3);
	printf("=========================================================================================");
	gotoxy(0, 8);
	printf("=========================================================================================");
	gotoxy(0, 9);
	printf("=========================================================================================");
	gotoxy(32, 11);
	cout << "Viva la vida!	  We fight!";
	gotoxy(0, 13);
	printf("=========================================================================================");
	gotoxy(0, 14);
	printf("=========================================================================================");
	gotoxy(41, 16);
	cout << "南京大学";
	gotoxy(36, 17);
	cout << "计算机科学与技术系";
	gotoxy(41, 18);
	cout << "课程设计";
	gotoxy(38, 21);
	cout << "制作人：葛泽凡\n";
	Sleep(3000);
	return 0;
}
void update_field(int score, int blood, int life,short bomb, short m1, short m2, short m3, short m4, short m5){
	gotoxy(0, 0);
	printf("|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|得分：%d\n",score);
	for (int i = 0; i < HEIGHT; i++){
		printf("|");
		for (int j = 0; j < WIDTH; j++){
			printf("%c",battlefield[i][j]);
		}
		printf("|");
		
		printf("\n");
	}
	printf(" ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	printf("\t血量：%d\t生命：%d\t\t\n",blood,life);
	printf("\t剩余：炸弹：%d	L:%d	U:%d	I:%d	O:%d	P:%d \n",bomb,m1,m2,m3,m4,m5);
}
void const_display(){
	gotoxy(0,36);
	printf("\t操作方式：\tw,a,s,d 控制战机移动\tJ:子弹 K:炸弹\n");
	printf("\tL:人民闪现 U:社会主义好 I:人多力量大 \n\tO:女神的宽恕 P:最终决战奥义·凡哥的爱\n");
	printf("\t空格:暂停游戏\t长按T:退出游戏\n");
	printf("\t增益提示:纵向三个相同符号串，两种笑脸增益子弹\n\t爱心加命，百分号加血，梅花加炸弹，黑桃加魔法");
}
void game_interrupt(){
	gotoxy(0, 14);
	printf("\t\t\t\t  Game over\n\t\t\t  Player has stopped the game!\n");
	gotoxy(0, 30);
}
void game_over(int score){
	gotoxy(0, 14);
	printf("\t\t\t\t  Game over\n\t\t\t  Your Total Score :%d\n",score);
	gotoxy(0, 30);
}
void game_win(int s){
	gotoxy(0, 14);
	printf("\t\t\t\t  You Win!!\n\t\t\t  Your Final Score :%d\n", s);
	gotoxy(0, 17);
	printf("\t泽凡·兰博粉碎了BUG星人的图谋，再一次证明了无产阶级走向胜利的历史必然。\n\t  为表彰英勇的程序员战士，习大大赠与程序员们民族英雄纪念版机械键盘，\n\t\t\t  并授予泽凡兰博计算队长称号。\n");
	printf("\t\t\t  Captain CS ，never die !！");
	gotoxy(0, 30);
	Sleep(5000);
}