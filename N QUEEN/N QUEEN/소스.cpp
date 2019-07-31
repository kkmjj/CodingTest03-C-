#include<iostream>
// N QUEEN -> back tracking ¹®Á¦ 

using namespace std;

int arr[11][11];
int check[11];
int check1[2 * 11];
int check2[2 * 11];
int N;

int answer = 0;

void dfs(int y)
{

	if (y == N)
	{
		answer++;
		return;
	}


	for (int i = 0; i < N; i++)
	{
		int right = y + i;
		int left = (N - 1) - (y - i);
		if (check[i])continue;
		if (check1[right])continue;
		if (check2[left])continue;

		check[i] = 1;
		check1[right] = 1;
		check2[left] = 1;
		
		cout << y << " " << i;
		cout << endl;
		dfs(y + 1);
		check[i] = 0;
		check1[right] = 0;
		check2[left] = 0;

		

	}



	
	
}


int main() {

	cin >> N;


	dfs(0);
	

	cout << answer;


}