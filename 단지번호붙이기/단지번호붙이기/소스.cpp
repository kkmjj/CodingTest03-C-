#include<iostream>
#include<algorithm>

using namespace std;

int N;
char map[26][26];
int apart[26 * 26];
int cnt;

int dfs(int y,int x) 
{
	map[y][x] = '2';
	int ay[] = {1,0,0,-1};
	int ax[] = {0,1,-1,0};

	for (int i = 0; i < 4; i++)
	{
		int newy = y + ay[i];
		int newx = x + ax[i];

		if (newx >= 0 && newy >= 0 && newx <= N && newy <= N
			&& map[newy][newx]=='1')
		{
			cnt++;
			map[newy][newx] = '2';
			dfs(newy, newx);
			
		}


	}


	return cnt;


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
	// ют╥б 
	int count = 0;
	int temp = 0;
	int answer = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (map[i][j] == '1')
			{
				cnt = 1;
				temp=dfs(i, j);
				apart[count] = temp;
				count++;
			}
		}

	}

	cout << count;
	cout << endl;

	sort(apart, apart + count);

	for (int i = 0; i < count; i++)
	{
		cout << apart[i];
		cout << endl;
	}



}