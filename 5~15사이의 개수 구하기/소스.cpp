// lower 5이상 중에서 가장 작은값의 위치 
// up 15이하중에서 가장 큰 값 위치 
#include<iostream>
using namespace std;
int N, M;
int arr[200000];
int Lowtemp = -1;
int uptemp = -1;

int LowBinary(int start, int end, int data) // 5보다 큰값 찾기 
{
	int m;
	Lowtemp = -1;

	while (start <= end) // 왼쪽 
	{
		m = (start + end) / 2;
		
		if (data < arr[m]) // 데이터 보다 크면 
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





int upBinary(int start, int end, int data) // 15보다 작은값 찾기 
{
	int m;
	uptemp = -1;

	while (start <= end)
	{
		m = (start + end) / 2;
			
		if (data > arr[m]) // 데이터 보다 작으면 
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
	 LowBinary(0, N - 1, 5);// 5이상 중에서 가장 작은 값의 위치
	
	if(Lowtemp!=-1)
	{
		upBinary(0, N - 1, 15); //15이하중에서 가장 큰값의 위치 
		cout << uptemp - Lowtemp + 1;
	}



}