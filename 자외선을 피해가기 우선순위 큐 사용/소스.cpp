#include<iostream>
#include<queue>
#include<functional>
#include<vector>


using namespace std;
int N;
char arr[102][102];
int visit[102][102];// 메모이제이션 
int cnt = 0;


struct type
{
	int r;
	int c;
	int sun;
	bool operator()(type a, type b) {
		 return a.sun > b.sun;
		
	}

}; 

type start;



void bfs(int row, int col)
{
	int arow[] = { 0,-1,0,1 };
	int acol[] = { 1,0,-1,0 };

	priority_queue<type,vector<type>,type> q;
	start.r = row;
	start.c = col;

	q.push(start);
	visit[start.r][start.c] = 1;

	while (!q.empty())
	{
		type temp = q.top();
		q.pop();
		if(temp.r == N && temp.c == N)
		{	
			cnt = temp.sun;
			return;
		}

		for (int i = 0; i < 4; i++)
		{
			int new_r = temp.r + arow[i];
			int new_c = temp.c + acol[i];

			if (new_r > 0 && new_c > 0 && new_r <= N && new_c <= N && visit[new_r][new_c]!=1)
			{
				visit[new_r][new_c] = 1;
				type next;
				next.r = new_r;
				next.c = new_c;
				next.sun = temp.sun + arr[next.r][next.c] - '0';
				q.push(next);
				


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
			
		}
	}
	// 입력 

	


	bfs(1, 1);
	
	cout << cnt;



}