#include<iostream>
#include<stdio.h>
using namespace std;

int N, M; // ����ġ�� ���� , ó���� ���� ����

int tree[1000 * 3];

void reverse(int node, int s, int e, int idx)
{
	int m;

	if (s == e) { // �����Ͱ� ������ �� �ִ� �� 

		tree[node] = tree[node] == 1 ? 0 : 1; // 1�̸� 0���� �ƴϸ� 1

		return;
	}

	m = (s + e) / 2;
	if (idx <= m) reverse(node * 2, s, m, idx);
	else reverse(node * 2 + 1, m + 1, e, idx);

	tree[node] = tree[node * 2] + tree[node * 2 + 1];

}

int switch_count(int node, int s, int e, int qs, int qe)
{
	int left, right;
	int m;

	if (qs <= s && e <= qe)
	{
		return tree[node];
	}
	else if (e < qs || qe < s)return 0;

	m = (s + e) / 2;
	left = switch_count(node * 2, s, m, qs, qe);
	right = switch_count(node * 2 + 1, m + 1, e, qs, qe);

	return left + right;
}





int main() {

	scanf("%d%d", &N, &M);
	for (int i = 1; i <= M; i++)
	{
		int O, S, T;
		scanf("%d%d%d", &O, &S, &T);  // O���� 0�̸� S~T�� ����ġ ���¸� ���� /1�̸� ����ġ �� �����ִ� ���� 

		if (O == 0)
		{
			for (int j = S; j <= T; j++)
			{
				reverse(1, 1, N, j);
			}
		

		}
		else if (O == 1) printf("%d",switch_count(1, 1, N, S, T));
		

	}




}