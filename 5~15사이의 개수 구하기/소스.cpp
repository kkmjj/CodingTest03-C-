// lower 5�̻� �߿��� ���� �������� ��ġ 
// up 15�����߿��� ���� ū �� ��ġ 
#include<iostream>
using namespace std;
int N, M;
int arr[200000];
int Lowtemp = -1;
int uptemp = -1;

int LowBinary(int start, int end, int data) // 5���� ū�� ã�� 
{
	int m;
	Lowtemp = -1;

	while (start <= end) // ���� 
	{
		m = (start + end) / 2;
		
		if (data < arr[m]) // ������ ���� ũ�� 
		{
			Lowtemp = m;
			end = m - 1;

		}
		else
		{
			start = m + 1;


		}
		


	}

	return Lowtemp;
}





int upBinary(int start, int end, int data) // 15���� ������ ã�� 
{
	int m;
	uptemp = -1;

	while (start <= end)
	{
		m = (start + end) / 2;
			
		if (data > arr[m]) // ������ ���� ������ 
		{
			uptemp = m;
			start = m + 1;

		}
		else
		{
			end = m -1;


		}



	}

	return uptemp;
}





int main() {


	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
	// 1 1 1 6 9 11 13 17 19 20
	 LowBinary(0, N - 1, 5);// 5�̻� �߿��� ���� ���� ���� ��ġ
	
	if(Lowtemp!=-1)
	{
		upBinary(0, N - 1, 15); //15�����߿��� ���� ū���� ��ġ 
		cout << uptemp - Lowtemp + 1;
	}



}