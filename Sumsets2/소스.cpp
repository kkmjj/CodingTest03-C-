#include<iostream>

using namespace std;

int K;
int a[7] = { 1,2,4,8,16,32,64 };
int rec[65];

int cnt = 0;


void dfs(int cur, int start,int sum)
{
	if (sum > K)return;

	if (sum == K)
	{
		for (int i = 0; i < cur; i++)
		{
			cout << rec[i] << " ";
		}
		cout << endl;
		cnt++;
		return;
	}

	for (int i = start; i < 7; i++)
	{
		
		rec[cur] = a[i];
		dfs(cur + 1, i, sum + a[i]);
		
	}








}



int main() {
	int T;
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		cin >> K;
		cnt = 0;
		dfs(0, 0, 0);
		cout << cnt<< " ";










	}







}