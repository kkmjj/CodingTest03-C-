#include<iostream>
using namespace std;

int N, M; // 배열의 개수 , 찾는데이터 개수 
int arr[50001];


int Binarysearch(int start, int e, int data)
{

	int m;
	while (start <= e)
	{
		 m= (e + start) / 2;

		if (arr[m] == data)return m+1; // 중앙에 있는값이 찾는데이터면 return

		else if (arr[m] < data) // 찾고자하는 데이터가 더 크면 오른쪽에서 
		{
			start = m + 1;
	
		}
		else			// 찾고자하는데이터가 더 작으면 오른쪽 
		{
			e = m - 1;
		}


	}

	return 0;








}



int main() {

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
	// 입력 

	cin >> M;
	for (int i = 0; i < M; i++)
	{
		int data;
		cin >> data; // 찾고자하는 데이터 

	
		cout << Binarysearch(0, N - 1,data);
		cout << endl;

		}
















	}




