#include<iostream>

using namespace std;

int N;
char map[101][101];
int visit[101][101];


void dfs(int y, int x,char a)
{
	visit[y][x] = 1;
	int ay[] = { 1,-1,0,0 };
	int ax[] = { 0,0,1,-1 };


	for (int i = 0; i < 4; i++)
	{
		int newy = y + ay[i];
		int newx = x + ax[i];
		if (newy >= 0 && newx >= 0 && newy < N  && newx < N 
			&& map[newy][newx]==a&& visit[newy][newx]==0)
		{
			visit[newy][newx] = 1;
			dfs(newy, newx,a);

		}
	}

	

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
	int count = 0;
	int count2 = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (visit[i][j] == 0)
			{
				dfs(i, j, map[i][j]);
				count++;
			}
		}

	}

	
	//녹색을 적색으로 바꾸기 visit 초기화
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (map[i][j] == 'G')map[i][j] = 'R';
			visit[i][j] = 0;
		}

	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (visit[i][j] == 0)
			{
				dfs(i, j, map[i][j]);
				count2++;
			}
		}

	}

	cout << count <<" "<< count2;


}