#include<iostream>

using namespace std;



int main() {

	double start;
	double end;
	double sum=0; // �� �ð��� �ð� ���ϱ� 
	int won = 0;

	for (int i = 1; i <= 5; i++) // 5�� ������ ���

	{
		cin >> start >> end;
		double temp;
		temp = end - start; // �Ϸ� ������ �ð���� 
		temp = temp - 1; // 1�ð� ���� 

		if (temp <0)temp = 0;  // �ּ� 1�ð��� �Ѿ�� ����
	
			
			if (temp > 4)temp = 4;

		

		sum += (temp);
	}

	won = (sum * 10000);// 0.5(30��) ������ 5000�� �� ����

	if (sum >= 15) won=won * 0.95;
	else if(sum <=5) won=won * 1.05;

	 

	cout << won;












}