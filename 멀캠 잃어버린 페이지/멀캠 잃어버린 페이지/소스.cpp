#include<iostream>

using namespace std;

int main() {

	int arr[251][5]; // 1���� �����ؼ� 4�������� �ִ� 250
	int N;  // ��ü ������ �� 
	int P; // ��� ������

	cin >> N >> P; // �Է��� �޴´� 

	// ���δ� ��ü����/4�� �ϸ� �ȴ�.
	int cnt = 1;
	int index = 0;

	for (int i = 1; i <= N / 4; i++)
	{
		for (int j= 1; j <= 2; j++) // �տ� ���������� �ϴ� ����
		{
			arr[i][j] = cnt;
			cnt++;
			if (arr[i][j] == P) // �ش��������̸� ����
			{
				index = i;
			}
		}
	}


	for (int i = N/4; i >=1; i--)
	{
		for (int j = 3; j <= 4; j++) // �ڿ� �������� ����
		{
			arr[i][j] = cnt;
			cnt++;
			if (arr[i][j] == P) // �ش��������̸� ����
			{
				index = i;
			}
		}
	}


	for (int i = 1; i <= 4; i++)
	{
		if (arr[index][i] != P) cout << arr[index][i]<< " ";
	}





}