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
	//1,4,3,2 -> 아래 오른쪽 위 왼쪽 
	for (int i = 0; i < 4; i++)
	{
		if (direct[i] == 1) newx = 1, newy = 0; // 아래 
		if (direct[i] == 2) newx = 0, newy = -1; //왼쪽
		if (direct[i] == 3) newx = -1, newy = 0; // 위
		if (direct[i] == 4) newx = 0, newy = 1; // 오른쪽



		while (x >= 0 && y >= 0 && x < N && y < N && map[x][y] == '0') // 범위 안에 있으면 
		{
			map[x][y] = '2';
			x += newx;
			y += newy;
			count++;

			if (x < 0 || y < 0 || x >= N || y >= N) { // 다음값이 범위를 벗어나면
				x -= newx, y -= newy, count--; 
				map[x][y] = '0';
				break;
			}

			if (map[x][y] == '1') {   // 다음 값이 1이면 
				x -= newx, y -= newy, count--;
				map[x][y] = '0';
				break;
			}

			if(map[x][y]=='2') return count;  //다음값이 이미 지나온 길이면 

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
	// 입력 


	for (int i = 0; i < 4; i++)
	{
		cin >> direct[i];
	}
	// 이동 방향 입력 

	int answer = 0;
	int temp = 1;

	while (map[x][y]!='2')
	{
		temp = move();
		answer += temp;
	}

	cout << answer-1;
	


}