#include<iostream>

using namespace std;


char map[10][10];
int direct[4];
int N;
int x = 0;
int y = 0;

int move()
{

	int count = 0;
	int newx;
	int newy;
	//1,4,3,2 -> �Ʒ� ������ �� ���� 
	for (int i = 0; i < 4; i++)
	{
		if (direct[i] == 1) newx = 1, newy = 0; // �Ʒ� 
		if (direct[i] == 2) newx = 0, newy = -1; //����
		if (direct[i] == 3) newx = -1, newy = 0; // ��
		if (direct[i] == 4) newx = 0, newy = 1; // ������



		while (x >= 0 && y >= 0 && x < N && y < N && map[x][y] == '0') // ���� �ȿ� ������ 
		{
			map[x][y] = '2';
			x += newx;
			y += newy;
			count++;

			if (x < 0 || y < 0 || x >= N || y >= N) { // �������� ������ �����
				x -= newx, y -= newy, count--; 
				map[x][y] = '0';
				break;
			}

			if (map[x][y] == '1') {   // ���� ���� 1�̸� 
				x -= newx, y -= newy, count--;
				map[x][y] = '0';
				break;
			}

			if(map[x][y]=='2') return count;  //�������� �̹� ������ ���̸� 

		}

	}
	return count;

}







int main() {


	cin >> N;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> map[i][j];
		}
	}
	// �Է� 


	for (int i = 0; i < 4; i++)
	{
		cin >> direct[i];
	}
	// �̵� ���� �Է� 

	int answer = 0;
	int temp = 1;

	while (map[x][y]!='2')
	{
		temp = move();
		answer += temp;
	}

	cout << answer-1;
	


}