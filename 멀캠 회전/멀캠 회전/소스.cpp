#include<iostream>
using namespace std;

int arr[50][50];
int N;

void rotation()
{
	


	for (int i = 0; i < N / 2; i++) { // �Ѻκп� �ִ� ����
		for (int j = i; j <(N-1)-i; j++) { // ���� ��� N=3 -> (0,0)���� (0,1) �� ����ϸ� �� (�ѹ��� 4�� �ٲٱ� )
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
	}// �Է� 
	
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