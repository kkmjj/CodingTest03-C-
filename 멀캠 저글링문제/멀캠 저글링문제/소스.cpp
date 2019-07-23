#include <queue>
#include <iostream>
using namespace std;



struct robot
{
	int x, y, time;
};


char map[150][150];
queue<robot> q;
int c, r;


int answer = 3;
int bfs(int cc, int rr)
{


	robot a;
	a.x = cc;
	a.y = rr;
	a.time = 3;

	map[a.y][a.x] = '0';

	q.push(a); // 처음 값 넣기 


	while (!q.empty())
	{
		robot temp = q.front();
		q.pop(); // 꺼냄 


		int dx[4] = { 0, 0, -1, 1 };
		int dy[4] = { -1, 1, 0, 0 };

		for (int i = 0; i < 4; i++)
		{
			robot next;
			next.x = temp.x + dx[i];
			next.y = temp.y + dy[i];
			next.time = temp.time + 1;

			if (next.x >= 1 && next.x <= c && next.y >= 1 && next.y <= r) // 범위 안에 있으면 
			{
				if (map[next.y][next.x] == '1')
				{
					answer = next.time;
					q.push(next);
					map[next.y][next.x] = '0';
				}




			}





		}


	}

	return answer;
}




int main() {

	int startc, startr;


	cin >> c >> r;  //7 ,8   [8][7]

	for (int y = 1; y <= r; y++) {
		for (int x = 1; x <= c; x++) {
			cin >> map[y][x];

		}

	}
	cin >> startc >> startr; // 3, 5 [5][3]
	int cnt = 0;

	cout << bfs(startc, startr);
	cout << endl;



	for (int y = 1; y <= r; y++) {
		for (int x = 1; x <= c; x++) {

			if (map[y][x] == '1') cnt++;


		}
	}

	cout << cnt;



	return 0;

}

