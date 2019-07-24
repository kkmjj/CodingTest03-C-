#include<iostream>
#include<algorithm>

using namespace std;


int main() {

	int arr[200]; // 최대 200개 가능 
	int N;
	int T;
	cin >> N >> T;
	
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
	sort(arr,arr+N);


	int sum = 0;
	int index;
	for (i = 0; i < N; i++)
	{
		sum += arr[i];
		if (sum > T)
		{
			index = i;
			break;
		}
		if (sum == T)
		{
			index = i + 1;
			break;
		}
		
	}
	

	cout << i;






}