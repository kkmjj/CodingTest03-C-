#include<iostream>

using namespace std;



int main() {

	int N; // N을 넘지 않는 7의배수이면서 짝수 
	cin >> N;
	int temp = 0;

	while (temp <= N)
	{
		temp += 14; // 7을 증가 

	
		

	}

	if (N < 14)
	{
		cout << 14;
	}

	else
	{
		int answer = 0;
		answer = N - (temp - 14) < temp - N ?  (temp - 14) : temp;
		if (N - (temp - 14) == temp - N) {
			answer = temp - 14;
		}

		cout << answer;
	}






}