#include<iostream>

using namespace std;

int main() {

	int arr[251][5]; // 1부터 시작해서 4페이지씩 최대 250
	int N;  // 전체 페이지 수 
	int P; // 뜯는 페이지

	cin >> N >> P; // 입력을 받는다 

	// 세로는 전체개수/4를 하면 된다.
	int cnt = 1;
	int index = 0;

	for (int i = 1; i <= N / 4; i++)
	{
		for (int j= 1; j <= 2; j++) // 앞에 두페이지만 일단 저장
		{
			arr[i][j] = cnt;
			cnt++;
			if (arr[i][j] == P) // 해당페이지이면 저장
			{
				index = i;
			}
		}
	}


	for (int i = N/4; i >=1; i--)
	{
		for (int j = 3; j <= 4; j++) // 뒤에 두페이지 저장
		{
			arr[i][j] = cnt;
			cnt++;
			if (arr[i][j] == P) // 해당페이지이면 저장
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