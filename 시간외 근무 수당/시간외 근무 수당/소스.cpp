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

		if (temp <1)temp = 0;  // �ּ� 1�ð��� �Ѿ�� ����

		if (temp >= 4)temp = 4; // �ִ� 4�ð� ���� 
		cout << temp;
		cout << endl;
		sum += (temp-1);
	}
	cout << sum;
	cout << endl;
	won = (sum / 0.5) * 5000; // 0.5(30��) ������ 5000�� �� ���� 

	cout << won;












}