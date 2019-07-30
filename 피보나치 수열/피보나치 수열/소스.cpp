#include<iostream>

using namespace std;
int N;
int dp[41];
int cnt = 1;
/*
int pivo(int start) {

	
	dp[start] = dp[start - 1] + dp[start - 2];
	cnt++;
	if (cnt == N)return dp[start];

	
	return pivo(start+1);


}*/


int main() {

	cin >> N;

	dp[0] = 0;
	dp[1] = 1;

	//cout << pivo(2);

	for (int i = 2; i < 2 + N; i++)
	{
		dp[i] = dp[i - 1] + dp[i - 2];
	}

	cout << dp[N];




}