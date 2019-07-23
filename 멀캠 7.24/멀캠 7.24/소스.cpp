#include<stdio.h>

int arr[100][100];
int main()
{

	int N;
	scanf("%d", &N); // 색종이 개수

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


	int count = 0;
	for (int i = 0; i <= 99; i++) {
		for (int j = 0; j <= 99; j++) {

			
			if (arr[i][j] >= 1)count++;

		}
	}

	printf("%d", count);





}