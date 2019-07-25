#include<iostream>

using namespace std;



int number_sum(int num)
{
	int digitRoot = 0;


	for (;;) {
		digitRoot = 0;
		while (num != 0) {
			digitRoot += num % 10;
			num /= 10;

		}
		num = digitRoot;
		if (num / 10 == 0) return num;

	}

	
}


int main() {
	int n, num, cur, answer = 0, max = 0;


	cin >> n;


	for (int i = 0; i < n; i++) {
		cin >> num;
		cur = number_sum(num);
		
		if (max == cur)
		{
			answer = answer < num ? answer : num;
		}

		if (max < cur) {
			max = cur;
			answer = num;

		}


	}

	cout << answer;

	return 0;

}


	
	









