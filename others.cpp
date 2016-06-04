struct Frame{//边框架构设计
	COORD position[2];
	int flag;
};
void SetPos(COORD a){//在a点坐标上输出特定内容
	HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(out, a);
}
void SetPos(int i, int j){
	COORD pos = { i, j };
	SetPos(pos);
}
void drawRow(int y, int x1, int x2, char ch){//把第y行，[x1, x2) 之间的坐标填充为 ch
	SetPos(x1, y);
	for (int i = 0; i <= (x2 - x1); i++)cout << ch;
}
void drawRow(COORD a, COORD b, char ch){//在a, b 纵坐标相同的前提下，把坐标 [a, b] 之间填充为 ch
	if (a.Y == b.Y)
		drawRow(a.Y, a.X, b.X, ch);
	else{
		SetPos(0, 25);
		cout << "error code 01：无法填充行，因为两个坐标的纵坐标(x)不相等";
		system("pause");
	}
}
void drawCol(int x, int y1, int y2, char ch){//在a, b 纵坐标相同的前提下，把坐标 [a, b] 之间填充为 ch
	int y = y1;
	while (y != y2 + 1){
		SetPos(x, y);
		cout << ch;
		y++;
	}
}
void drawCol(COORD a, COORD b, char ch){//在a, b 横坐标相同的前提下，把坐标 [a, b] 之间填充为 ch
	if (a.X == b.X)
		drawCol(a.X, a.Y, b.Y, ch);
	else{
		SetPos(0, 25);
		cout << "error code 02：无法填充列，因为两个坐标的横坐标(y)不相等";
		system("pause");
	}
}
void drawFrame(COORD a, COORD  b, char row, char col)//左上角坐标、右下角坐标、用row填充行、用col填充列
{
	drawRow(a.Y, a.X + 1, b.X - 1, row);
	drawRow(b.Y, a.X + 1, b.X - 1, row);
	drawCol(a.X, a.Y + 1, b.Y - 1, col);
	drawCol(b.X, a.Y + 1, b.Y - 1, col);
}
void drawFrame(int x1, int y1, int x2, int y2, char row, char col){
	COORD a = { x1, y1 };
	COORD b = { x2, y2 };
	drawFrame(a, b, row, col);
}
void drawFrame(Frame frame, char row, char col){
	COORD a = frame.position[0];
	COORD b = frame.position[1];
	drawFrame(a, b, row, col);
}
void drawPlaying(){//画游戏区域
	/*system("cls");
	system("mode con cols=100 lines=60");
	drawFrame(0, 0, 65, 43, '~', '|');
	drawFrame(66, 0, 99, 4, '-', '|');
	drawFrame(66, 4, 99, 9, '-', '|');
	drawFrame(66, 9, 99, 20, '-', '|');
	drawFrame(66, 20, 99, 24, '-', '|');*/
	SetPos(60, 5);
	cout << "得分：";
	SetPos(60, 6);
	cout << "血量：";
	SetPos(60, 7);
	cout << "生命：";
	SetPos(60, 8);
	cout << "水平：";
	SetPos(60, 10);
	cout << "操作方式：";
	SetPos(60, 12);
	cout << "  w,a,s,d 控制战机移动。";
	SetPos(60, 13);
	cout << "  J:子弹 K:炸弹";
	SetPos(60, 14);
	cout << "  L:社会主义好 U:死不了";
	SetPos(60, 15);
	cout << "  I:影分身 O:女神的宽恕";
	SetPos(60, 16);
	cout << "  P:最终决战奥义·凡哥的爱";
	SetPos(60, 17);
	cout << "  空格:暂停游戏";
	SetPos(60, 18);
	cout << "  T:退出游戏 R:重新开始";
	SetPos(60, 22);
	cout << "增益提示:";
	SetPos(0, 45);
}