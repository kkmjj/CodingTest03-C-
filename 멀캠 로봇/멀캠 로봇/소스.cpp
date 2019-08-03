#include<iostream>
#include<queue>
using namespace std;

int N;
int M;
int startr = 0;
int startw = 0;
int start_ = 0;
int endr = 0;
int endw = 0;
int end_ = 0;

 struct robot
{
	int r;
	int w;
	int dir;
	int cnt;

};


queue<robot> q;
int arr[101][101];
int visit[5][110][110]; //동서남북 1면~4면까지 체크 
int dr[5] = {0,0,0,1,-1};
int dc[5] = {0,1,-1,0,0};  //동서 남북 (1,2,3,4)
int turn[5][2] = { {0,0},    {4,3},{3,4},{1,2},{2,1} }; //1행-동서남북, 0열 왼쪽 1열 오른쪽 



int bfs(int r, int w, int dir, int cnt)
{
	robot start;
	start.r = r;
	start.w = w;
	start.dir = dir;
	start.cnt = cnt;
	q.push(start);
	visit[start.dir][start.r][start.w] = 1;
	
	while (!q.empty())
	{//1. go1 go2 go3 진행 
		robot temp;
		temp = q.front();
		q.pop();

		if (temp.r == endr&& temp.w == endw && temp.dir == end_)
		{
			while (!q.empty())q.pop();
			return temp.cnt;
			break;
		}

		for (int i = 1; i <= 3; i++)
		{
			int newr = temp.r + dr[temp.dir]*i;		// 방향에 따른 나아갈 좌표 설정
			int neww = temp.w + dc[temp.dir]*i;
			int newdir = temp.dir;
			
		// 다음 가볼 좌표의 맵의 범위 체크 
			if (visit[newdir][newr][neww] == 1)continue;
			if (newr < 0 && neww < 0 && newr >= N && neww >= M)continue;
			if (arr[newr][neww] == 1)break; //  막혀있으면 아예 나와야함 
			
					robot next;
					next.r = newr;
					next.w = neww;
					next.dir = temp.dir;
					next.cnt = cnt + 1;
					visit[next.dir][next.r][next.w] = 1;
					q.push(next);


		}

		// turn left , right

		for (int i = 0; i < 2; i++) // 0은 왼쪽 턴, 1은 오른쪽턴 
		{
			int newdir = turn[temp.dir][i];  // 바라보는 방향 설정 
			int newr = temp.r;
			int neww = temp.w;
			if (visit[newdir][newr][neww] == 1)continue;
					robot next;
					next.r = newr;
					next.w = neww;
					next.dir = newdir;
					next.cnt = cnt + 1;
					visit[next.dir][next.r][next.w] = 1;
					q.push(next);
				
			
			// 다음 방향의 방문 체크 


		}
	
	}







}






int main() {

	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{

		for (int j = 0; j < M; j++)
		{
			cin >> arr[i][j];
		}


	}
	// 입력 
	
	cin >> startr >> startw >> start_;
	cin >> endr >> endw >> end_;


	cout << bfs(startr, startw, start_, 0);





}