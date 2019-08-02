#include<iostream>
#include<algorithm>

using namespace std;

int N;
int	M;  // N개중 M개 구하기 

int h[13];
int temp[13];

int a[64];
int cnt = 0;
int min = 0;
int max = 0;



void allset() {
	for (int i = 0; i < 64; i++)
	{
		a[i] = 0;
	}
}

void dfs(int cur,int start) {

	if (cur >= M) {

		/*for (int i = 0; i < M; i++)
		{
			cout << temp[i];
		
		}
		cout << endl;
		*/
		
		cnt++;
		


		return;
	}


	for (int i = start; i < 64; i++)
	{

		if (a[i] >= 1)
		{
			
			a[i]--;
			temp[cur] = a[i];
			dfs(cur + 1, i );
			a[i] ++;
		}
		
		
		

	}





}



int main() {

	int T;
	cin >> T;



	for (int i = 0; i < T; i++)
	{
		cnt = 0;
		allset();
	
		cin >> N >> M;

		for (int i = 0; i < N; i++)
		{
			cin >> h[i];
			a[h[i]]++;
			
		}

		

		dfs(0,1);
		cout << cnt;
		cout << endl;

	






	}









}