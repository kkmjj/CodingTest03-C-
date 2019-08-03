#include<iostream>
#include<queue>
using namespace std;

/*

6 4 1
0 0 0 0 0 0
0 0 0 0 0 0
0 0 0 0 0 0
0 0 0 0 0 1

*/
struct tomato
{
	int h;
	int r;
	int w;

};




int arr[102][102][102];
int temp[102][102][102];
queue<tomato> q;

int main()
{
	int t = 0;
	int M; // ���� w
	int N; // ���� r
	int H;

	cin >> M >> N >> H;

	for (int k = 1; k <= H; k++)
	{
		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= M; j++)
			{
				cin >> arr[k][i][j];
				if (arr[k][i][j] == 1) {
					tomato temp;
					temp.h = k;
					temp.r = i;
					temp.w = j;
					q.push(temp);
				}
			}
		}
	}
	// �Է�







	//bfs ���� 
	while (!q.empty())
	{
		tomato a = q.front(); // ó���� �̰�
		q.pop();

		int ah[] = { 1, -1,0,0,0,0 };
		int ax[] = { 0,0,1,0,-1,0 };
		int ay[] = { 0,0,0,1,0 ,-1 };


		for (int i = 0; i < 6; i++)
		{
			tomato next;
			next.r = a.r + ax[i];
			next.w = a.w + ay[i];
			next.h = a.h + ah[i];

			if (next.h >= 1 && next.h <= H && next.r >= 1 && next.r <= N && next.w >= 1 && next.w <= M)//�����ȿ� ������ 
			{
				if (arr[next.h][next.r][next.w] == 0) // �������� ������
				{
					arr[next.h][next.r][next.w] = 1;
					temp[next.h][next.r][next.w] = temp[a.h][a.r][a.w] + 1;
					//������ +1 count�ϸ鼭 ���� �ᱹ ������ ���� �����  
					t = temp[next.h][next.r][next.w];
					q.push(next);
				}


			}



		}
	}
		

	





	for (int k = 1; k <=H; k++)
	{
		for (int i = 1; i <= N; i++) // �������� ������ -1
		{
			for (int j = 1; j <= M; j++)
			{
				if (arr[k][i][j] == 0) // �������� ������
				{
					t = -1;
				}
			}


		}
	}

	cout << t;








}