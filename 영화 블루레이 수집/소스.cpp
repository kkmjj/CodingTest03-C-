#include<iostream>
#include<stdio.h>
using namespace std;

int T, N, M; // 테스트 케이스 블루레이수 영화의 개수 

int tree[200000 * 3];
int pos[100001]; // cd의 위치 기록 

void update(int node, int s, int e, int idx, int data)
{
	int m;
	if (s == e)
	{
		tree[node] = data;
		return;
	}

	m = (s + e) / 2;
	if (idx <= m)update(node * 2, s, m, idx, data);
	else update(node * 2 + 1, m + 1, e, idx, data);

	
	tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

int Query(int node, int s, int e, int qs, int qe)
{
	int left, right;
	int m;

	if (qs <= s && e <= qe) //현재 구간이 구간내 포함 되어있으면 
	{
		return tree[node];

	}
	else if (e<qs || qe<s)return 0;

	m = (s + e) / 2;

	left = Query(node * 2, s, m, qs, qe);
	right = Query(node * 2 + 1, m + 1, e, qs, qe);

	return left + right;




}


int main() {

	scanf("%d", &T);
	for (int i = 0; i < T; i++)
	{
		

		scanf("%d%d", &N, &M); 

		for (int k = 1; k <= 200000 * 3; k++)tree[k] = 0;	// 초기화 
		for (int k = 1; k <= 100000; k++)pos[k] = 0;


		for (int j = 1; j <=N; j++)
		{
			pos[j] = M + j;// cd의 위치를 M (인덱스 CD번호 ,값이 위치 )
		
			update(1, 1, N+M, M+j,1); // idx번째에 cd 유무로 저장 

		}

		for (int j = 0; j < M; j++)
		{
			int data;
				scanf("%d", &data); // 3,1,1
				printf("%d ", Query(1, 1, N + M,1,pos[data]-1));
				update(1, 1, N + M, pos[data],0);
				// 개수구하기 
				update(1, 1, N + M, M-j, 1);
				pos[data] = M - j;
		}
		printf("\n");









	}



}