#include<iostream>
using namespace std;

char first[101][102];
char second[101][102];
bool v = true;
int M, N;


bool vs(int i,int j)
{

	for (int k = 0; k <M; k++)
	{
		for (int l = 0; l <M; l++)
		{
			if (first[k+i][l+j] == second[k][l])continue;
			else
			{
				return false;
			}

		}
	}
	return true;

}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> first[i][j];
		}
	}

	cin >> M;
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> second[i][j];
		}
	}
	// ют╥б 
	int cnt=0;

	for (int i = 0; i <= N-M; i++)
	{
		for (int j = 0; j <= N-M; j++)
		{


			v = vs(i, j);


			if (v) cnt++;


			
		}
	}

	cout << cnt;












}