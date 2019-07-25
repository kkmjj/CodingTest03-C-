#include<iostream>
#include<algorithm>
using namespace std;


int main() {
	int sum = 0;

	int N = 9;
	int arr[9];
	int a[2];


	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
		sum += arr[i];
	}
	sum -= 100;
	// 문제 예시 40  2개가지고 

	for (int i = 0; i < N; i++)
	{
		
		for (int j = 0; j < N; j++)
		{
			if (i == j)continue;

			if (arr[i] + arr[j] == sum)
			{
				a[0] = arr[i];
				a[1] = arr[j];
				cout << arr[0] << " " << arr[1];
				cout << endl;
			}

		}
	}
	sort(arr, arr + 9);

	/*for (int i = 0; i < N; i++)
	{
		if (a[0] == arr[i] || a[1] == arr[i])continue;
		cout << arr[i];
		cout << endl;
	}*/






}