#include<stdio.h>


char s[52][52];

int minsu = 0;
int count = 0;

int dfs(int x, int y)
{
	int sum = 0;
	int ax[] = {-1,-1,-1,0,0,1,1,1};
	int ay[] = {-1,0,1,-1,1,-1,0,1};

	for (int i = 0; i < 8; i++)
	{
		int newx = x + ax[i] ;
		int newy = y + ay[i] ;

		if (s[newx][newy] == 'o')
			{
				
				sum++;
			}
	
	}


	return sum;
}

int main()
{
	int R, C;
	scanf("%d %d", &R, &C);

	for (int i = 1; i <=R; i++)
	{
		scanf("%s", &s[i][1]);
	}
	// 입력
	int answer = 0;

	for (int i = 1; i <= R; i++)
	{
		for (int j = 1; j <=C; j++)
		{
			if (s[i][j] == 'o') // 무조건 기존사람들끼리 다 구해서 나누기 2를 하면 알아서 중복이 해결됨 
			{
				
				answer+=dfs(i, j);
			}
		}
	}

	answer = answer / 2; // 기존 사람들끼리만 한 악수의 개수 
	

	int minsu = 0;
	
	for (int i = 1; i <= R; i++)
	{
		for (int j = 1; j <= C; j++)
		{
			if (s[i][j] == '.') //민혁이가 들어갈 자리 
			{
				minsu = minsu < dfs(i, j) ? dfs(i, j) : minsu;
			}
		}
	}

	answer = answer + minsu;
	printf("%d", answer);





}