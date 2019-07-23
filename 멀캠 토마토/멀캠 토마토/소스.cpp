#include<iostream>
#include<queue>
using namespace std;

/*

6 4
0 0 0 0 0 0
0 0 0 0 0 0
0 0 0 0 0 0
0 0 0 0 0 1

*/
struct tomato
{
	int x;
	int y;

};




int arr[1002][1002];
int temp[1002][1002];
queue<tomato> q;

int main()
{
	int t = 0;
	int c;
	int r;

	cin >> c >> r;

	for (int i = 1; i <= r; i++)
	{
		for (int j = 1; j <= c; j++)
		{
			cin >> arr[i][j];
			if (arr[i][j] == 1) {
				tomato temp;
				temp.x = i;
				temp.y = j;
				q.push(temp);
			}
		}
	}
	// 입력


		//bfs 구현 
		while (!q.empty())
		{
			tomato a = q.front(); // 처음값 뽑고
			q.pop();

			int ax[] = { 0,1,-1,0 };
			int ay[] = { -1,0,0,1 };


			for (int i = 0; i < 4; i++)
			{
				tomato next;
				next.x = a.x + ax[i];
				next.y = a.y + ay[i];

				if (next.x >= 1 && next.x <= r && next.y >= 1 && next.y <= c)//범위안에 있으면 
				{
					if (arr[next.x][next.y] == 0) // 안익은게 있으면
					{
						arr[next.x][next.y] = 1;
						temp[next.x][next.y] = temp[a.x][a.y] + 1; 
					//그전값 +1 count하면서 가면 결국 마지막 값이 결과값  
						t = temp[next.x][next.y];
						q.push(next);
					}


				}



			}

		}


		for (int i = 1; i <= r; i++) // 안익은게 있으면 -1
		{
			for (int j = 1; j <= c; j++)
			{
				if (arr[i][j] == 0) // 안익은게 있으면
				{
					t = -1;
				}
			}


		}

		cout << t;








}