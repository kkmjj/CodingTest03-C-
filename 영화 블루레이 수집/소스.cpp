#include<iostream>
#include<stdio.h>
using namespace std;

int T, N, M; // �׽�Ʈ ���̽� ��緹�̼� ��ȭ�� ���� 

int tree[200000 * 3];
int pos[100001]; // cd�� ��ġ ��� 

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

	if (qs <= s && e <= qe) //���� ������ ������ ���� �Ǿ������� 
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

		for (int k = 1; k <= 200000 * 3; k++)tree[k] = 0;	// �ʱ�ȭ 
		for (int k = 1; k <= 100000; k++)pos[k] = 0;


		for (int j = 1; j <=N; j++)
		{
			pos[j] = M + j;// cd�� ��ġ�� M (�ε��� CD��ȣ ,���� ��ġ )
		
			update(1, 1, N+M, M+j,1); // idx��°�� cd ������ ���� 

		}

		for (int j = 0; j < M; j++)
		{
			int data;
				scanf("%d", &data); // 3,1,1
				printf("%d ", Query(1, 1, N + M,1,pos[data]-1));
				update(1, 1, N + M, pos[data],0);
				// �������ϱ� 
				update(1, 1, N + M, M-j, 1);
				pos[data] = M - j;
		}
		printf("\n");









	}



}