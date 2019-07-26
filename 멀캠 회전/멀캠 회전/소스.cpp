#include<iostream>
using namespace std;

int arr[50][50];
int N;

void rotation()
{
	


	for (int i = 0; i < N / 2; i++) { // 겉부분에 있는 원소
		for (int j = i; j <(N-1)-i; j++) { // 예를 들어 N=3 -> (0,0)부터 (0,1) 만 계산하면 끝 (한번에 4개 바꾸기 )
			int temp = arr[i][j];
			
			arr[i][j] = arr[(N - 1) - j][i];
			arr[(N - 1)- j][i] = arr[(N - 1) - i][(N - 1) - j];
			arr[(N - 1)- i][(N - 1) - j] = arr[j][(N - 1) - i];
			arr[j][(N - 1) - i] = temp;
		}
		
	}

	





}



int main() {


	cin >> N;

	for (int i = 0; i < N; i++)
	{
		for (int j=0; j < N; j++)
		{
			cin >> arr[i][j];
		}
	}// 입력 
	
	int c = 1;

	while (c != 0)
	{
		cin >> c;

		if (c != 90 && c != 180 && c != 270 && c != 360)continue;
		int cnt = c / 90;

		for (int k= 0; k < cnt; k++)
		{
			rotation();
		}


		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				cout << arr[i][j]<< " ";
			}
			cout << endl;
		}




	}

	

	









}