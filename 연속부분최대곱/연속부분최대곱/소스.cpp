#include<iostream>

using namespace std;




int main() {
	
	double a[10000];
	double dp[10000];
	
	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> a[i];
	}
	//ют╥б 
	double max = 0;
	dp[0] = a[N-1];

	for (int i = 1; i < N; i++)
	{
		dp[i] = dp[i - 1] * a[N - (i + 1)] < a[N - (i + 1)] ? a[N - (i + 1)] : dp[i - 1] * a[N - (i + 1)];
		if (max < dp[i])max = dp[i];
	}

	printf("%.3f", max);
}