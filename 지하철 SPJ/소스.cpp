#include<iostream>
#include<queue>

using namespace std;

int N, M; // 지하철수 ,목적역 현재는1부터 
int arr[102][102];
int visit[102][102];



struct type
{
	int r;// 현재 위치 
	int time;
	vector<int> a;
	bool operator()(type a, type b)
	{
		return a.time > b.time;   // 거짓이면 1 리턴 
	}

};

type start;

priority_queue<type,vector<type>,type> q;

int cnt = 0;


void bfs(int row)
{

	visit[1][row] = 1;
	start.r = 1;
	start.a.push_back(row);
	start.time = arr[1][1];
	q.push(start);


	while (!q.empty())
	{
		type temp = q.top();
		q.pop();
		if (temp.r == M) {

			cout << temp.time;
			cout << endl;
			for (int i = 0; i < temp.a.size(); i++)
			{
				cout << temp.a[i] <<" ";
			}
			cnt = temp.time;
			return;
		}

		for (int i = 1; i <= N; i++)
		{

			if (visit[temp.r][i] != 1&&arr[temp.r][i]!=0)
			{
				visit[temp.r][i] = 1;
				type next;
				next.r = i;
				next.time = temp.time + arr[temp.r][i];
				for (int j = 0; j < temp.a.size(); j++) next.a.push_back(temp.a[j]);
				next.a.push_back(next.r);				
				q.push(next);


			}



		}

	}

}





int main() {

	cin >> N >> M;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			cin >> arr[i][j];
		}
	}
	// 입력 



	bfs(1); // 1번부터 시작 

	




}