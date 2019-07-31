#include<iostream>
#include<vector>

// DFS 기본 문제  FOR 2개 돌리고 재귀를 이해 해보고 DFS 구현 
/*
	for(i=0;i<=6;i++)
	{
	for(j=0;j<=6;j++)
	{
	}
	}

*/
using namespace std;

int N, M;
int cnt = 0;
int arr[8];
int sum = 0;
void dfs(int depth)
{
	if (depth > N) {
		for (int i = 1; i <= N; i++) {
			sum += arr[i];
		}
		if (sum == M)
		{
			for (int i = 1; i <= N; i++) {
				cout << arr[i];
			}
			cout << endl;
		}
		sum = 0;
		return;
	}
	
	for (int i = 1; i <= 6; i++)
	{
		arr[depth] = i;
		dfs(depth+1);
	}

}


int main() {


	cin >> N >> M;

	dfs(1);

}