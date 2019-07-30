#include<iostream>
#include<queue>
using namespace std;

int N, M;
int map[101][101];
int check[101][101];

int endy, endx;

struct target
{
	int y;
	int x;
	int count=0;
};


int bfs(int y, int x)
{
	bool visit = false;
	int count = 0;
	int ay[] = { -2,-1,1,2,2,1,-1,-2};
	int ax[] = { 1,2,2,1,-1,-2,-2,-1 }; // 8방향 


	queue<target> q;
	target a;
	a.y = y;
	a.x = x;
	q.push(a);
	check[a.y][a.x] = 1;
	while (!q.empty() && !visit)
	{
		target temp = q.front();
		q.pop();

		for (int i = 0; i < 8; i++)
		{
			target next;
			next.y = temp.y + ay[i];
			next.x = temp.x + ax[i];
			next.count = temp.count + 1;

			if (next.y >= 1 && next.y < N && next.x >= 1 && next.x < M &&check[next.y][next.x] == 0)
			{

				if (next.y == endy && next.x == endx)	// 범위 안에 있고 목표에 도달
				{

					count = next.count;
					visit = true;
					while (!q.empty())q.pop();

					return count;


				}
				else
				{
					check[next.y][next.x] = 1;
					q.push(next);
				}
			}

		}


	}







}


int main() 
{
	int starty;
	int startx;

	cin >> N >> M;


	cin >> starty >> startx;
	cin >> endy >> endx;

	cout <<	bfs(starty, startx);







}