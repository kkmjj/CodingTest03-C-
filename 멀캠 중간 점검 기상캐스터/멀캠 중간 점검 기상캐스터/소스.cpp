#include<iostream>

using namespace std;

char cloud[102][102];
int  answer[102][102];
int main() {

	int N;
	int M;
	cin >> N;
	cin >> M;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> cloud[i][j];
		}
	}
	// �Է� 
	bool v = false; // ó�� ���� üũ 
	int index; // ����� ������ ��ġ 

	for (int i = 0; i < N; i++)
	{
		v = false;
		int cnt = 0;
		for (int j = 0; j < M; j++)
		{
			if (v&&cloud[i][j] == 'c') {
				index = j;
				answer[i][j] = j-index;
				continue;
			}
			
			if (cloud[i][j] == 'c')
			{
				v = true;
				index = j;
				answer[i][j] = j-index;
			
				continue;

			}

			if (v) {
				
				answer[i][j] = j-index;
			}
			else {
				answer[i][j] = -1;
			}


		}
	}


	
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cout << answer[i][j]<< " ";
		}
		cout << endl;

	}














}