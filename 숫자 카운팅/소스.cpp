#include<iostream>

using namespace std;
// �̺� Ž���� �ؼ� ã�����ϴ� �����͸� ã���� �� ���ʿ��� �ٽ� �����͸� ã�� ���� . ���߿��� ���� ���� �� ã�´�
//-> e <s �ϋ� ���� 

// �̺� Ž���� �ؼ� ã�����ϴ� �����͸� ã���� �� ���ʿ��� �ٽ� �����͸� ã�� ���� . ���߿��� ���� ���� �� ã�´�
//-> e <s �ϋ� ���� 
int N, M;
int arr[200000];
int Lowtemp=-1;
int uptemp=-1;

int LowBinary(int start, int end, int data)
{
	int m;
	Lowtemp = -1;

	while (start <= end) // ���� 
	{
		m = (start + end) / 2;

		if (arr[m] == data) 
		{ // �����Ͱ� ������ �� ���� lower�� ���� 
			Lowtemp = m;
			end= m - 1;
		}

		else if (arr[m] < data)  // ã�°��� �� ũ�� ������ Ž��
		{
			start = m + 1;
		}
		else end = m - 1;


	}

	return Lowtemp;
}





int upBinary(int start, int end, int data)
{
	int m;
	uptemp = -1;

	while (start <=end) 
	{
		m = (start + end) / 2;

		if (arr[m] == data) 
		{ // �����Ͱ� ������ �� ���� up�� ���� 
			uptemp = m;
			start = m +  1;
		}

		else if (arr[m] < data)  // ã�°��� �� ũ�� ������ Ž��
		{
			start = m + 1;
		}
		else end = m - 1;


	}

	return uptemp;
}





int main() {


	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}

	cin >> M;
	for (int i = 0; i < M; i++)
	{
		int data;
		cin >> data;

		LowBinary(0, N - 1, data);
		if (Lowtemp != -1)
		{
			upBinary(0, N - 1, data);
			cout << uptemp - Lowtemp + 1 << " ";
		}
		else cout << "0"<<" ";
	}







}