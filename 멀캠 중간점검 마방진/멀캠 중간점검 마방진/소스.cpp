#include<iostream>

using namespace std;

int arr[99][99];

int main() {



	int N;
	cin >> N;
	// 입력 

	
  // arr[0][N / 2] = 1;
   int indexr = 0;
   int indexc = N / 2;
//	arr[N - 1][N / 2 - 1] = 2;

	for (int i = 1; i <= N*N; i++)
	{
		arr[indexr][indexc] = i;
		if (i%N == 0) // 3의 배수이면 
		{
			indexr++;
			if (indexr > N ) indexr = 0; // 범위 벗어나면 0으로 

			//arr[indexr][indexc] = i;

		}
		else
		{
			indexr--;
			indexc--;
			if (indexr < 0) {
				indexr = N - 1;
	
			}
			if (indexc < 0) {
				indexc = N-1;
			}

			//arr[indexr][indexc] = i;



		}


	}



	for (int i = 0; i <N; i++)
	{
		for (int j = 0; j <N; j++)
		{
			cout << arr[i][j]<<" ";
		}
		cout <<endl;
	}




}