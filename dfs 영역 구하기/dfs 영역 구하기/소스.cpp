#include<iostream>
#include<algorithm>

using namespace std;

int M, N, K;
int map[101][101];
int cnt;
int a[101 * 101];

int dfs(int y, int x)
{
	map[y][x] = 2;
	int ay[] = { 1,0,0,-1 };
	int ax[] = { 0,1,-1,0 };



	for (int i = 0; i < 4; i++)
	{
		int newy = y + ay[i];
		int newx = x + ax[i];

		if (newx >= 0 && newy >= 0 && newx < N && newy < M 
		&& map[newy][newx] == 0)
		{
			map[newy][newx] = 2;
			cnt++;
			dfs(newy, newx);
		}



	}



	return cnt;



}


int main() {

	cin >> M >> N >> K;
	int starty;
	int startx;
	int endy;
	int endx;

	for (int i = 0; i < K; i++)
	{
		cin >> startx >> starty >> endx >> endy;

		for (int y = starty; y <endy; y++)
		{
			for (int x = startx; x <endx; x++)
			{
				map[y][x] = 1;
			}
		}

	}
	// 모든 직사각형에 1 표시 
	int count = 0;
	int temp = 0;

	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			
			if (map[i][j] == 0) {
				cnt = 1;
				temp = dfs(i, j);
				a[count] = temp;
				count++;
			}

		}



	}

	cout << count;
	cout << endl;
	sort(a, a + count);
	for (int i = 0; i < count; i++)
	{
		cout << a[i];
		cout << endl;
	}




}