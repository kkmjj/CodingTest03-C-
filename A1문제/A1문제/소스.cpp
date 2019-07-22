#include <iostream>
#include <stack>

using namespace std;
/*
입력 :
5
0 1
1 2
2 3
3 2
6 1

출력 : 2


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
		// 속도만 순서대로 넣기 
	}
	int size = s.size();
	int temp = s.top();// 맨 뒤에 속도값 
	for(int i=0;i<size;i++)
	{
		
		s.pop();

		if (s.empty())break;

		if ( temp < s.top()) // 앞에 속도보다 빠르면 언젠가 잡힘 
		{
			continue;
		}

		group++;
		temp = s.top();
	}


	cout << group;






}
