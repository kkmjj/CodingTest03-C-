#include<iostream>

using namespace std;
// 이분 탐색을 해서 찾고자하는 데이터를 찾으면 그 왼쪽에서 다시 데이터를 찾아 나감 . 그중에서 가장 왼쪽 을 찾는다
//-> e <s 일떄 멈춤 

// 이분 탐색을 해서 찾고자하는 데이터를 찾으면 그 왼쪽에서 다시 데이터를 찾아 나감 . 그중에서 가장 왼쪽 을 찾는다
//-> e <s 일떄 멈춤 
int N, M;
int arr[200000];
int Lowtemp=-1;
int uptemp=-1;

int LowBinary(int start, int end, int data)
{
	int m;
	Lowtemp = -1;

	while (start <= end) // 왼쪽 
	{
		m = (start + end) / 2;

		if (arr[m] == data) 
		{ // 데이터가 있으면 그 값을 lower에 저장 
			Lowtemp = m;
			end= m - 1;
		}

		else if (arr[m] < data)  // 찾는값이 더 크면 오른쪽 탐색
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
		{ // 데이터가 있으면 그 값을 up에 저장 
			uptemp = m;
			start = m +  1;
		}

		else if (arr[m] < data)  // 찾는값이 더 크면 오른쪽 탐색
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