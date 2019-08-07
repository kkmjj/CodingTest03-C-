#include<iostream>

using namespace std;
int N, T; // ������ ���� ,�׽�Ʈ ����

int arr[50000 * 3];

void update(int node , int s, int e, int idx, int data){
	int m;
	if (s == e) {
		arr[node] += data;
		return;
	}
	m = (s + e) / 2;
	if (idx <= m) update(node * 2, s, m, idx, data);
	else update(node * 2 + 1, m + 1, e, idx, data);

	arr[node] = arr[node * 2] + arr[node * 2 + 1]; // ���� ������ ������ 



}

int query(int node, int s, int e, int qs, int qe) // s=1 e =N
{
	int left, right;
	int m = (s + e) / 2;

	if (qs <= s && e <= qe) return arr[node];

	else if (e < qs || qe < s)return 0;

	left = query(node * 2, s, m, qs, qe);
	right = query(node * 2 + 1, m + 1, e, qs, qe);

	return left + right;

}

int main() {

	cin >> N >> T;

	for (int i = 1; i <= N; i++)
	{
		int data;
		cin >> data;
		update(1, 1, N, i, data);
	}
	for (int i = 1; i <= T; i++)
	{
		int qs, qe, idx, add;
		cin >> qs >> qe >> idx >>add;
		// ���� ������ �κ��� ���ϱ� 
		cout << query(1, 1, N, qs, qe);
		//idx��° ����Ÿ�� add��ŭ �����Ͽ� ���� 
		update(1, 1, N, idx, add);

	}





}