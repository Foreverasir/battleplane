#include <iostream>
#include <windows.h>
#include <conio.h>	//getch()
#include <stdlib.h> //system��������ͷ�ļ�
#include "SomeConst.h"
#define stoptimelong 800
using namespace std;

//���ع��
void HideCursor(){
	CONSOLE_CURSOR_INFO cursor_info = { 1, 0 };
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
}
//������Ļָ�����꣬�˴���װһ��
void gotoxy(int x, int y){
	CONSOLE_SCREEN_BUFFER_INFO  csbiInfo;
	HANDLE  hConsoleOut = GetStdHandle(STD_OUTPUT_HANDLE);
	GetConsoleScreenBufferInfo(hConsoleOut, &csbiInfo);
	csbiInfo.dwCursorPosition.X = x;
	csbiInfo.dwCursorPosition.Y = y;
	SetConsoleCursorPosition(hConsoleOut, csbiInfo.dwCursorPosition);
}
void Start_display(){//���ÿ���̨��ɫ����������Ըı���Ļ���������ɫ
	system("cls");
	gotoxy(18, 5);
	system("color 0E");
	printf("�c	    ��Ԫ2015�꣬");
	Sleep(stoptimelong);
	printf("������������Σ����");
	Sleep(stoptimelong);
	gotoxy(25, 7);
	printf("а��İ͸�������������˷��Ľ�����");
	Sleep(stoptimelong);
	gotoxy(27, 9);
	printf("��Ϊ���������ȷ�ĳ���Գ�׵���塣");
	Sleep(stoptimelong);
	gotoxy(31, 11);
	printf("���������������˱����ˡ���");
	Sleep(stoptimelong);
	gotoxy(29, 13);
	printf("�����ԣ���BUG��֧��ĺڰ����¡�");
	Sleep(stoptimelong);
	gotoxy(25, 15);
	printf("���ڣ�ΰ�������������Գսʿͦ�����");
	Sleep(stoptimelong);
	gotoxy(37, 17);
	printf("��");Sleep(500);
	printf("��");Sleep(500);
	printf("��");Sleep(500);
	printf("��");Sleep(500);
	printf("��");Sleep(500);
	printf("��");Sleep(500);
	printf("��");Sleep(500);
	gotoxy(22, 19);
	printf("������ȫ�����ϣ������ʻ�޲��׼�һ�ų���ƽ���㡣");
	Sleep(stoptimelong);
	gotoxy(34, 21);
	printf("		 Fight  or  Die!!	�f");
	cout << endl << endl;
	printf("				  ���밴�������ʼ��\n");
	_getch();
}
int drawMenu(){
	system("mode con cols=90 lines=50");//�ı����̨��С
	gotoxy(0, 1);
	printf("=========================================================================================");
	gotoxy(33, 2);
	cout << "<$  �M ��  ��  B U G  $>" << endl;
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
	cout << "�Ͼ���ѧ";
	gotoxy(36, 17);
	cout << "�������ѧ�뼼��ϵ";
	gotoxy(41, 18);
	cout << "�γ����";
	gotoxy(38, 21);
	cout << "�����ˣ�����\n";
	Sleep(3000);
	return 0;
}
void update_field(int score, int blood, int life,short bomb, short m1, short m2, short m3, short m4, short m5){
	gotoxy(0, 0);
	printf("|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|�÷֣�%d\n",score);
	for (int i = 0; i < HEIGHT; i++){
		printf("|");
		for (int j = 0; j < WIDTH; j++){
			printf("%c",battlefield[i][j]);
		}
		printf("|");
		
		printf("\n");
	}
	printf(" ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	printf("\tѪ����%d\t������%d\t\t\n",blood,life);
	printf("\tʣ�ࣺը����%d	L:%d	U:%d	I:%d	O:%d	P:%d \n",bomb,m1,m2,m3,m4,m5);
}
void const_display(){
	gotoxy(0,36);
	printf("\t������ʽ��\tw,a,s,d ����ս���ƶ�\tJ:�ӵ� K:ը��\n");
	printf("\tL:�������� U:�������� I:�˶������� \n\tO:Ů��Ŀ�ˡ P:���վ�ս���塤����İ�\n");
	printf("\t�ո�:��ͣ��Ϸ\t����T:�˳���Ϸ\n");
	printf("\t������ʾ:����������ͬ���Ŵ�������Ц�������ӵ�\n\t���ļ������ٷֺż�Ѫ��÷����ը�������Ҽ�ħ��");
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
	printf("\t�󷲡�����������BUG���˵�ͼı����һ��֤�����޲��׼�����ʤ������ʷ��Ȼ��\n\t  Ϊ����Ӣ�µĳ���Ասʿ��ϰ����������Ա������Ӣ�ۼ�����е���̣�\n\t\t\t  ����������������ӳ��ƺš�\n");
	printf("\t\t\t  Captain CS ��never die !��");
	gotoxy(0, 30);
	Sleep(5000);
}