#include<iostream>
#include<queue>
using namespace std;

int N, M;
int chicken_index=0; // 현재 도시의 치킨의 개수 
int apart_index = 0;
// chicken 중에서 M개 고르기 
int arr[22][22];
int answer = 100000;
int ans = 100000;

struct apart
{
	int row;
	int col;
}apart[100];

struct chicken
{
	int row;
	int col;
	int km = 0;
}chicken[20];


struct temp
{
	int row;
	int col;
	int km = 0;
}temp[20];


void dfs(int cur,int start)
{
	if (cur >= M)
	{
		answer = 0;
		for (int i = 0; i < cur; i++)
		{
		cout << temp[i].row << " " << temp[i].col<<" min";
			int min =10000;
			for (int j = 0; j < apart_index; j++)
			{
				min = min < abs(temp[i].row - apart[j].row) + abs(temp[i].col - apart[j].col) ?
					min : abs(temp[i].row - apart[j].row) + abs(temp[i].col - apart[j].col);
			}
			//cout << min << " temp.km";
			temp[i].km = min;
			//cout << temp[i].km << " answer";
			answer += temp[i].km;
			//cout << answer << " ";

		}
		ans = ans < answer ? ans : answer;
		cout << endl;

		return;
	}


	for (int i = start; i < chicken_index; i++)
	{

		temp[cur].row = chicken[i].row;
		temp[cur].col = chicken[i].col;
		dfs(cur + 1, i + 1);


	}







}


int main() {
	cin >> N;
	cin >> M;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> arr[i][j];
			if (arr[i][j] == 2)
			{
				chicken[chicken_index].row = i;
				chicken[chicken_index].col = j;
				chicken_index++;
			}
			if (arr[i][j] == 1)
			{
				apart[apart_index].row = i;
				apart[apart_index].col = j;
				apart_index++;
			}
		}
	}
	// 입력 



	dfs(0, 0);


	cout << ans;






}