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
	// �Է�


		//bfs ���� 
		while (!q.empty())
		{
			tomato a = q.front(); // ó���� �̰�
			q.pop();

			int ax[] = { 0,1,-1,0 };
			int ay[] = { -1,0,0,1 };


			for (int i = 0; i < 4; i++)
			{
				tomato next;
				next.x = a.x + ax[i];
				next.y = a.y + ay[i];

				if (next.x >= 1 && next.x <= r && next.y >= 1 && next.y <= c)//�����ȿ� ������ 
				{
					if (arr[next.x][next.y] == 0) // �������� ������
					{
						arr[next.x][next.y] = 1;
						temp[next.x][next.y] = temp[a.x][a.y] + 1; 
					//������ +1 count�ϸ鼭 ���� �ᱹ ������ ���� �����  
						t = temp[next.x][next.y];
						q.push(next);
					}


				}



			}

		}


		for (int i = 1; i <= r; i++) // �������� ������ -1
		{
			for (int j = 1; j <= c; j++)
			{
				if (arr[i][j] == 0) // �������� ������
				{
					t = -1;
				}
			}


		}

		cout << t;








}