#include<iostream>

using namespace std;



int main() {

	int N; // N�� ���� �ʴ� 7�ǹ���̸鼭 ¦�� 
	cin >> N;
	int temp = 0;

	while (temp <= N)
	{
		temp += 14; // 7�� ���� 

	
		

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