#include<iostream>

using namespace std;
int N, ans;
int w[20];
int temp[20];
int check[20];
int sum = 0;
int cnt = 0;
int tm=0;

void dfs(int cur)
{
	if (cur >= N)
	{
		sum = 0;
		cnt = 0;
		for (int i = 0; i < cur; i++)
		{
			
			if (temp[i] == 0)continue;
			int AS = temp[i];
			int sum_temp = sum;
			while (sum_temp != 0 || AS != 0) // 더하기 전 sum과 들어온 temp[i]와 비교
			{
				if (sum_temp % 10 + AS % 10 >= 10) return; // 10을 초과하면 return;

				sum_temp /= 10;
				AS /= 10;


			}

			sum += temp[i];
			cnt++;
			cout << temp[i] << " "<<sum<<" ";

		}

		tm = cnt < tm ? tm : cnt;


		cout << endl;



	
		return;
	}
	
	temp[cur] = w[cur];
	dfs(cur + 1);
	temp[cur] = 0;
	dfs(cur + 1);



}

int main() {

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> w[i];
	}

	dfs(0);

	cout << tm;

}