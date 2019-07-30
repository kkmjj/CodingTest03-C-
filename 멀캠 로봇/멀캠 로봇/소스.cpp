#include<iostream>
#include<queue>

using namespace std;

int N;
int M;

int map[101][101];

struct target
{
	int y;
	int x;
	int eye;
};

target start;
target endtarget;

void bfs(int y,int x, int eye)
{
	queue<target> q;
	target a;
	a.y = y;
	a.x = x;
	a.eye = eye;
	q.push(a);
	while (!q.empty())
	{
		int ay[3];
		int ax[3];
		target temp;
		temp = q.front();
		q.pop();
		if (temp.eye == 1) {
			ay[0] = 0, ay[1] = -1, ay[2] = 1;
			ax[0] = 1, ax[1] = 0, ay[2] = 0;

		}
		if (temp.eye == 2) {
			ay[0] = 0, ay[1] = 1, ay[2] = -1;
			ax[0] = -1, ax[1] = 0, ax[2] = 0;

		}
		if (temp.eye == 3) {
			ay[0] = 1, ay[1] = 0, ay[2] = 0;
			ax[0] = 0, ax[1] = 1, ax[2] = -1;

		}
		if (temp.eye == 4)
		{
			ay[0] = -1, ay[1] = 0, ay[2] = 0;
			ax[0] = 0, ax[1] = -1, ax[2] = 1;

		}


		for (int i = 0; i < 4; i++)
		{
			target next;
			next.y = temp.y + ay[i];
			next.x = temp.x + ax[i];
			next.eye = temp.eye;

			







		}




		

	}








}


int main() {
	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> map[i][j];
		}
	}
	// 입력 
	// 1 동 2서 3남 4북 

	cin >> start.y >> start.x >> start.eye;
	cin >> endtarget.y >> endtarget.x >> endtarget.eye;


	bfs(start.y, start.x, start.eye);








}