#include<iostream>

using namespace std;

int arr[1001];

int main() {
	int N;
	cin >> N;

	int max = 0;
	int min = 10000;
	int highmax = 0;
	int mid = 0;
	for (int i = 0; i < N; i++)
	{
		int index;
		int high;

		cin >> index >> high;
		if (highmax <= high)  // �ְ� ������ �ε��� ���ϱ�
		{
			highmax = high;
			mid = index;
		}

		arr[index] = high;

		min = min > index ? index : min;
		max = max < index ? index : max; // �ִ� �ּ� index���ϱ�

	}

	// �Է� 


	int left = arr[min]; // ó�� ���� ��ŭ ä��� 
	int right = arr[max]; // ������ ���� 

	for (int i = min; i <= mid; i++) // ���ʿ��� �̵� 
	{
		if (arr[i] <= left) // ���� ���� left���� ������ ä�� �ֱ� 
		{
			arr[i] = left;
		}
		else // ũ�� �� 
		{
			left = arr[i];
		}


	}

	
		for (int i = max; i >= mid; i--) // �����ʿ��� �̵�  
		{
			if (arr[i] <= right) // ���� ���� right���� ������ ä�� �ֱ� 
			{
				arr[i] = right;
			}
			else // ũ�� �� 
			{
				right = arr[i];
			}


		}
	

	int answer = 0;

	
		for (int i = min; i <= max; i++)
		{
			answer += arr[i];
		}
	

	cout << answer;



}