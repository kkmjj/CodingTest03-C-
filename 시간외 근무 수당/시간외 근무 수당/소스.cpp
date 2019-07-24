#include<iostream>

using namespace std;



int main() {

	double start;
	double end;
	double sum=0; // 총 시간외 시간 더하기 
	int won = 0;

	for (int i = 1; i <= 5; i++) // 5일 동안의 계산

	{
		cin >> start >> end;
		double temp;
		temp = end - start; // 하루 동안의 시간계산 
		temp = temp - 1; // 1시간 빼고 

		if (temp <0)temp = 0;  // 최소 1시간은 넘어야 인정
	
			
			if (temp > 4)temp = 4;

		

		sum += (temp);
	}

	won = (sum * 10000);// 0.5(30분) 단위로 5000원 을 받음

	if (sum >= 15) won=won * 0.95;
	else if(sum <=5) won=won * 1.05;

	 

	cout << won;












}