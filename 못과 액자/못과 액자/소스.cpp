#include<iostream>
using namespace std;

int N;
int map[101][101];
int check[5];
int direct[5];
int cnt = 0;

struct mot {
	int y;
	int x;

}pin[5];

struct ac
{
	int y;
	int x;

}a[5];

int answer = 0;

void allset()
{
	for (int i = 0; i < 100; i++)
	{
		for (int j = 0; j < 100; j++)
		{
			map[i][j] = 0;
		}
	}

}

int allsum()
{
	int cnt = 0;
	for (int i = 0; i < 100; i++)
	{
		for (int j = 0; j < 100; j++)
		{
			if (map[i][j] == 1)cnt++;
		}
	}

	return cnt;
}




void dfs(int number)
{
	struct mot  temp= pin[number]; // �ش� �� 

	if (number == N)
	{
		cnt = 0;
		cnt=allsum();
		answer = answer < cnt ? cnt : answer;
		allset();
		return;
	}


	for (int i = 1; i <= N; i++) //���� i
	{
		if (check[i])continue;

		check[i] = 1;

		for (int y = temp.y; y <temp.y+ a[i].y; y++)
		{
			for (int x = temp.x/2 +1 ; x <temp.x/2 + a[i].x; x++)
			{
				map[y][x] = 1;
			}
		}
		direct[i] = 1;
		dfs(number + 1); // ���� ���� ��� ���� 
		for (int y = temp.y; y <temp.y + a[i].y; y++)
		{
			for (int x = temp.x / 2 + 1; x <temp.x / 2 + a[i].x; x++)
			{
				map[y][x] = 0;
			}
		}

		for (int y = temp.y; y <temp.y + a[i].x; y++)
		{
			for (int x = temp.x / 2 + 1; x <temp.x / 2 + a[i].y; x++)
			{
				map[y][x] = 1;
			}
		}

		direct[i] = 2;
		dfs(number + 1); // ���� ���� ��� ���� ( 90ȸ�� �Ѱ�  �ΰ��� dfs �ϸ� �� )
		check[i] = 0;


	}








}



int main() {
	cin >> N;

	for (int i = 1; i <= N; i++)
	{
		cin >> pin[i].y >> pin[i].x;
	}
	// ����  ��ġ 

	for (int i = 1; i <= N; i++)
	{
		cin >> a[i].y >> a[i].x;
	}
	// ���� ũ�� 

	dfs(1); // 1�� �� ���� üũ 



	cout << answer;







}