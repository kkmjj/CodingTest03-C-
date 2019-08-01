#include<iostream>
#include<math.h>
using namespace std;

int N;
struct cook
{
	int s;
	int b;
}cook[11];

struct temp
{
	int s;
	int b;
}temp[11];

int answer = 0x7FFFFFFF;

void dfs(int cur, int min)
{
	

	if (cur >= N)
	{
		int sin_sum = 1;
		int bin_sum = 0;
		for (int i = 0; i < N; i++)
		{
			sin_sum *= temp[i].s;
			bin_sum += temp[i].b;
			
		}
		if (bin_sum == 0)return;
		answer = answer < abs(sin_sum - bin_sum) ? answer : abs(sin_sum - bin_sum);
		cout << answer;
		cout << endl;
		return ;
	}


	temp[cur].s = cook[cur].s;
	temp[cur].b = cook[cur].b;
	dfs(cur + 1, min);   // 재료가 들어가고 
	temp[cur].s = 1;
	temp[cur].b = 0;
	dfs(cur + 1, min); // 재료 안들어가고 


}


int main() {

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> cook[i].s >> cook[i].b;
	}
		//입력 

	dfs(0, 10000);

	cout << answer;



}