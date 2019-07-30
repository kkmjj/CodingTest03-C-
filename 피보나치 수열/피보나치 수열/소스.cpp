#include<iostream>

using namespace std;
int N;
int dp[41];
int cnt = 1;

int pivo(int start) {

	if (start == 2 || start == 1)return 1;
		
	if (dp[start] != 0)return dp[start];
	return dp[start] = pivo(start - 1) + pivo(start - 2);


}


int main() {

	cin >> N;

	dp[0] = 0;
	dp[1] = 1;

	cout << pivo(N);





}