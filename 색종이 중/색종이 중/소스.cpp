#include<stdio.h>


int arr[101][101]; // ������ ������ 90,90�ϰ�� ���� �پ��ϰ�� ���������� 1�� �� ũ�� �����.
int count = 0;

int bfs(int x, int y)
{
	int sum = 0;
	int ax[] = { 1,0,0,-1 };
	int ay[] = { 0,1,-1,0 };


	for (int i = 0; i < 4; i++)
	{
		int newx = x + ax[i];
		int newy = y + ay[i];

		if (arr[newx][newy] == 0)
		{
			sum++;
		}



	}


	return sum;

	
}


int main() 

{
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{

		int x;
		int y;
		scanf("%d %d", &x, &y);
		for (int k = y; k <= y + 9; k++)
		{

			for (int j = x; j <= x + 9; j++)
			{
				arr[k][j]++;
			}

		}
	}
	// 1�� ä���� ������ 
	

	for (int i = 0; i <= 99; i++) {
		for (int j = 0; j <= 99; j++) {


			if (arr[i][j] >= 1)
			{
				count+=bfs(i, j);
			}

		}
	}

	printf("%d", count);










}