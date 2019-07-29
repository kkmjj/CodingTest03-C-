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
		if (highmax <= high)  // 최고 높이의 인덱스 구하기
		{
			highmax = high;
			mid = index;
		}

		arr[index] = high;

		min = min > index ? index : min;
		max = max < index ? index : max; // 최대 최소 index구하기

	}

	// 입력 


	int left = arr[min]; // 처음 막대 만큼 채우기 
	int right = arr[max]; // 마지막 막대 

	for (int i = min; i <= mid; i++) // 왼쪽에서 이동 
	{
		if (arr[i] <= left) // 다음 값이 left보다 작으면 채워 넣기 
		{
			arr[i] = left;
		}
		else // 크다 면 
		{
			left = arr[i];
		}


	}

	
		for (int i = max; i >= mid; i--) // 오른쪽에서 이동  
		{
			if (arr[i] <= right) // 다음 값이 right보다 작으면 채워 넣기 
			{
				arr[i] = right;
			}
			else // 크다 면 
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