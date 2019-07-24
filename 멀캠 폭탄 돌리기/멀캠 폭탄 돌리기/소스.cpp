#include<iostream>
using namespace std;


int main() {

	int start; // 폭탄 가지고 있는 사람

	int N; // 문제 개수 
	cin >> start >> N;

	int time = 210;

	int t;
	int answer = 0;
	char v;
	bool stop = false;

	for (int i = 0; i < N; i++)
	{
		cin >> t >> v;  // 걸리는 시간과 통과여부 

		if (!stop)
		{
			switch (v)
			{
			case 'P': time -= t;

				break;

			case 'T': time -= t;
				if (time <= 0)break;
				start++;

				break;
			case 'F':time -= t;

				break;



			default:
				break;
			}
			if (start > 8)start -= 8;

		}
		if (time < 0)
		{
			answer = start;
			stop = true;
			

		}

		
	}

	cout << endl;
	cout << answer;

}