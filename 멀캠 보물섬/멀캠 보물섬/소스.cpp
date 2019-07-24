#include<iostream>
#include<queue>

using namespace std;

struct tree
{
	int x;
	int y;
	int cnt;
};

queue<tree> q;

char map[55][55]; //50이하 
int visit[55][55];
int c, r;
int answer = 0;

int bfs(int x, int y,int sum)
{

	for (int i = 1; i <= c; i++)
	{

		for (int j = 1; j <= r; j++)
		{
			visit[i][j] = 0;
		}
	} // 초기화 

	answer = 0;
	
	tree a;
	a.x = x;
	a.y = y;
	a.cnt = sum;
	q.push(a); // 처음값 
	while (!q.empty())
	{
		tree temp = q.front();
		q.pop();

		int ax[] = { 1,-1,0,0 };
		int ay[] = { 0,0,1,-1 };
		for (int i = 0; i < 4; i++)
		{
			tree next;
			next.x = temp.x + ax[i];
			next.y = temp.y + ay[i];
			

			if (next.x >= 1 && next.x <= c&& next.y >= 1 && next.y <= r) // 범위 안에 들었을떄 
			{
				if (map[next.x][next.y] == 'L'&&visit[next.x][next.y] !=1)
				{
					visit[next.x][next.y] =1;
					next.cnt = temp.cnt + 1;
					answer = next.cnt;
					q.push(next);
				}


			}







		}

	}

	return answer;




}





int main() {

	int result = 0;
	cin >> c >> r;

	
	for (int x = 1; x <= c; x++)
	{

		for (int y = 1; y <= r; y++)
		{
			cin >> map[x][y];
		}


	}
	// 입력 




	for (int x = 1; x <= r; x++)
	{

		for (int y = 1; y <= c; y++)
		{
			if (map[x][y] == 'L')
			{
				int answer = bfs(x, y, 0);
				result = result < answer ? answer : result;
			}
		}
	}



	cout << result;





}