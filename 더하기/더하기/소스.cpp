#include<iostream>

using namespace std;

int T;
int N;
int K;// ���� �� 
int a[21];
int b[21];
bool answer;

bool dfs(int cur, int sum)
{
	if (cur >= N)
	{
		if (sum == K)answer = true;
		
		return;
	}

	b[cur] = a[cur]; // �־�ΰ� 
	dfs(cur+1, sum + b[cur]);
	b[cur] = 0;    // �� �ְ� 
	dfs(cur+1, sum);





}


int main() {

	cin >> T;
	for (int i = 0; i < T; i++)
	{
		cin >> N >> K;

		for (int j = 0; j < N; j++)
		{
			cin >> a[j];
		}
		// �Է� 


		answer = false;
		if (dfs(0, 0))cout << "YES";
		else cout << "NO";
		cout << endl;
		







	}





}