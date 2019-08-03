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
int visit[5][110][110]; //�������� 1��~4����� üũ 
int dr[5] = {0,0,0,1,-1};
int dc[5] = {0,1,-1,0,0};  //���� ���� (1,2,3,4)
int turn[5][2] = { {0,0},    {4,3},{3,4},{1,2},{2,1} }; //1��-��������, 0�� ���� 1�� ������ 



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
	{//1. go1 go2 go3 ���� 
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
			int newr = temp.r + dr[temp.dir]*i;		// ���⿡ ���� ���ư� ��ǥ ����
			int neww = temp.w + dc[temp.dir]*i;
			int newdir = temp.dir;
			
		// ���� ���� ��ǥ�� ���� ���� üũ 
			if (visit[newdir][newr][neww] == 1)continue;
			if (newr < 0 && neww < 0 && newr >= N && neww >= M)continue;
			if (arr[newr][neww] == 1)break; //  ���������� �ƿ� ���;��� 
			
					robot next;
					next.r = newr;
					next.w = neww;
					next.dir = temp.dir;
					next.cnt = cnt + 1;
					visit[next.dir][next.r][next.w] = 1;
					q.push(next);


		}

		// turn left , right

		for (int i = 0; i < 2; i++) // 0�� ���� ��, 1�� �������� 
		{
			int newdir = turn[temp.dir][i];  // �ٶ󺸴� ���� ���� 
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
				
			
			// ���� ������ �湮 üũ 


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
	// �Է� 
	
	cin >> startr >> startw >> start_;
	cin >> endr >> endw >> end_;


	cout << bfs(startr, startw, start_, 0);





}