#include <iostream>
#include <stack>

using namespace std;
/*
�Է� : 
5
0 1
1 2
2 3
3 2
6 1

��� : 2 


*/
int main()
{
	int N;
	int pos;
	int v;
	int group = 1;
	stack<int> s;

	cin >> N;
	

	for (int i = 0; i < N; i++)
	{
		cin >> pos >> v;

		s.push(v);
		// �ӵ��� ������� �ֱ� 
		}

	while (!s.empty())
	{
		int temp=s.top();// �� �ڿ� �ӵ��� 
		s.pop();

		if (temp < s.top())
		{
			continue;
		}

		group++;
	}


	cout << group;






}
