struct Frame{//�߿�ܹ����
	COORD position[2];
	int flag;
};
void SetPos(COORD a){//��a������������ض�����
	HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(out, a);
}
void SetPos(int i, int j){
	COORD pos = { i, j };
	SetPos(pos);
}
void drawRow(int y, int x1, int x2, char ch){//�ѵ�y�У�[x1, x2) ֮����������Ϊ ch
	SetPos(x1, y);
	for (int i = 0; i <= (x2 - x1); i++)cout << ch;
}
void drawRow(COORD a, COORD b, char ch){//��a, b ��������ͬ��ǰ���£������� [a, b] ֮�����Ϊ ch
	if (a.Y == b.Y)
		drawRow(a.Y, a.X, b.X, ch);
	else{
		SetPos(0, 25);
		cout << "error code 01���޷�����У���Ϊ���������������(x)�����";
		system("pause");
	}
}
void drawCol(int x, int y1, int y2, char ch){//��a, b ��������ͬ��ǰ���£������� [a, b] ֮�����Ϊ ch
	int y = y1;
	while (y != y2 + 1){
		SetPos(x, y);
		cout << ch;
		y++;
	}
}
void drawCol(COORD a, COORD b, char ch){//��a, b ��������ͬ��ǰ���£������� [a, b] ֮�����Ϊ ch
	if (a.X == b.X)
		drawCol(a.X, a.Y, b.Y, ch);
	else{
		SetPos(0, 25);
		cout << "error code 02���޷�����У���Ϊ��������ĺ�����(y)�����";
		system("pause");
	}
}
void drawFrame(COORD a, COORD  b, char row, char col)//���Ͻ����ꡢ���½����ꡢ��row����С���col�����
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
void drawPlaying(){//����Ϸ����
	/*system("cls");
	system("mode con cols=100 lines=60");
	drawFrame(0, 0, 65, 43, '~', '|');
	drawFrame(66, 0, 99, 4, '-', '|');
	drawFrame(66, 4, 99, 9, '-', '|');
	drawFrame(66, 9, 99, 20, '-', '|');
	drawFrame(66, 20, 99, 24, '-', '|');*/
	SetPos(60, 5);
	cout << "�÷֣�";
	SetPos(60, 6);
	cout << "Ѫ����";
	SetPos(60, 7);
	cout << "������";
	SetPos(60, 8);
	cout << "ˮƽ��";
	SetPos(60, 10);
	cout << "������ʽ��";
	SetPos(60, 12);
	cout << "  w,a,s,d ����ս���ƶ���";
	SetPos(60, 13);
	cout << "  J:�ӵ� K:ը��";
	SetPos(60, 14);
	cout << "  L:�������� U:������";
	SetPos(60, 15);
	cout << "  I:Ӱ���� O:Ů��Ŀ�ˡ";
	SetPos(60, 16);
	cout << "  P:���վ�ս���塤����İ�";
	SetPos(60, 17);
	cout << "  �ո�:��ͣ��Ϸ";
	SetPos(60, 18);
	cout << "  T:�˳���Ϸ R:���¿�ʼ";
	SetPos(60, 22);
	cout << "������ʾ:";
	SetPos(0, 45);
}