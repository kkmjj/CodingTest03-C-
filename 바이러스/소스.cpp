#include<iostream>
using namespace std;

int N;
int M;
int arr[101][101];
int visit[101];
int cnt = 0;

void dfs(int start)
{

	for (int i = 1; i <= N; i++)
	{
		if (visit[i] != 1 && arr[start][i]==1) // 방문 안했고 연결 되어있는지 확인 
		{
			visit[i] = 1;
			cnt++;
			dfs(i);
		}
	}


}



int main() 
{
	int row, col;
	cin >> N;
	cin >> M;
	for (int i = 0; i < M; i++)
	{
	
		cin >> row >> col;
		arr[row][col] = 1;
		arr[col][row] = 1;
	}

	visit[1] = 1;


	dfs(1);

	cout << cnt;


}