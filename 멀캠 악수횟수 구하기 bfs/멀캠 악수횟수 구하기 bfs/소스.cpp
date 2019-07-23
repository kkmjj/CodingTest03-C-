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
	// �Է�
	int answer = 0;

	for (int i = 1; i <= R; i++)
	{
		for (int j = 1; j <=C; j++)
		{
			if (s[i][j] == 'o') // ������ ��������鳢�� �� ���ؼ� ������ 2�� �ϸ� �˾Ƽ� �ߺ��� �ذ�� 
			{
				
				answer+=dfs(i, j);
			}
		}
	}

	answer = answer / 2; // ���� ����鳢���� �� �Ǽ��� ���� 
	

	int minsu = 0;
	
	for (int i = 1; i <= R; i++)
	{
		for (int j = 1; j <= C; j++)
		{
			if (s[i][j] == '.') //�����̰� �� �ڸ� 
			{
				minsu = minsu < dfs(i, j) ? dfs(i, j) : minsu;
			}
		}
	}

	answer = answer + minsu;
	printf("%d", answer);





}