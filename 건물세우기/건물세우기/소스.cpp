#include<iostream>

using namespace std;

int N;
int arr[11][11];
int check[11];
int b[11]; // 값을 넣어 두고 다 더하기  
int sum = 1000000;
int cnt;


int dfs(int alpa) // 0->A 1>B 2->C
{
	if (alpa == N)
	{
		cnt = 0;
		for (int i = 0; i <alpa; i++)
		{
		
			cnt += b[i];
		
		}


		sum = cnt < sum ? cnt : sum;
		
		
	}

	for (int i = 0; i < N; i++)
	{
		if (check[i])continue;
		check[i] = 1;
		b[alpa] = arr[alpa][i];
		dfs(alpa + 1);
		check[i] = 0;

	}


	return sum;
}


int main() {
	cin >> N;

	for (int i = 0; i < N; i++) // A B C 
	{
		for (int j = 0; j < N; j++)
		{
			cin >> arr[i][j];
		}

	}
	// 입력 



	cout << dfs(0);








}