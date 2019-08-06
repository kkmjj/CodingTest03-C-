#include<iostream>
#include<queue>


using namespace std;
int N;
char arr[102][102];
int tmp[102][102];// 메모이제이션 


struct type
{
	int r;
	int c;

};

type start;

void bfs(int row, int col)
{
	int arow[] = { 0,-1,0,1 };
	int acol[] = { 1,0,-1,0 };

	queue<type> q;
	start.r = row;
	start.c = col;
	
	q.push(start);

	while (!q.empty())
	{
		type temp = q.front();
		q.pop();


		for (int i = 0; i < 4; i++)
		{
			int new_r = temp.r + arow[i];
			int new_c = temp.c + acol[i];

			if (new_r > 0 && new_c > 0 && new_r <= N && new_c <= N)
			{
				type next;
				next.r = new_r;
				next.c = new_c;
				
				if (tmp[next.r][next.c] > (arr[next.r][next.c]-'0') + tmp[temp.r][temp.c])
				{
					tmp[next.r][next.c] = (arr[next.r][next.c] - '0') + tmp[temp.r][temp.c];
					q.push(next);
				}

			

			}





		}

	}

}


int main() {
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			cin >> arr[i][j];
			tmp[i][j] = 10000000;
		}
	}
	// 입력 

	tmp[1][1] = 0;


	bfs(1, 1);
	cout << tmp[N][N];




}