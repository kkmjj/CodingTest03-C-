#include<iostream>

using namespace std;


int main() 
{
	int N;
	cin >> N; // ���� �Է� 

	double basic =(0.0277777)*100; // �� �ֻ����� Ȯ�� *100

	int number = 0;

	if (N <= 6) number = N - 1;

	else if (N > 6) number = 7 - (N - 6);
	

	basic = basic*number;
	printf("%.5f%%", basic);
	printf("%.4f%%", basic);
	basic = basic + 0.00005;
	printf("%.5f%%", basic);
	printf("%.4f%%", basic);






}