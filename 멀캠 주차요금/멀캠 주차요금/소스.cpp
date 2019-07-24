#include<iostream>
using namespace std;



int main() {
	int N; // 차량수 
	int time;
	int sum = 0;
	int car;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		car = 0;    // 해당 차에 대한 요금 
		cin >> time;
		

		if (time < 10) continue;

		car += 500;

		if (time > 30) //30분 추가시 
		{
			int temp=0;
			temp = time-30;
			if (temp % 10 == 0) car += (temp / 10) * 300;
			else
			{
				car += ((temp / 10)+1) * 300;
			}






		}

	
		if (car > 50000)car = 50000;
		sum += car;

	}





	cout << sum;















}