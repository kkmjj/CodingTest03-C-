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
	int size = s.size();
	int temp = s.top();// �� �ڿ� �ӵ��� 
	for(int i=0;i<size;i++)
	{
		
		s.pop();

		if (s.empty())break;

		if ( temp < s.top()) // �տ� �ӵ����� ������ ������ ���� 
		{
			continue;
		}

		group++;
		temp = s.top();
	}


	cout << group;






}
