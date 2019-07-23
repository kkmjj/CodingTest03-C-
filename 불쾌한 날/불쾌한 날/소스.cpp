#include<iostream>
#include<stack>
using namespace std;

int main()
{
	int cow[100];

	int i;
	int N;
	cin >> N;
	for (i = 0; i < N; i++)
	{
		cin >> cow[i];
	}
	// 문제 초기화 
	stack<int> s;

	int answer = 0;

	for (int i = 0; i < N; i++)
	{
		if (s.empty())
		{
			s.push(cow[i]);
			continue;
		}

		if (s.top() > cow[i]) // 맨앞에보다 소가 작으면 
		{
			
			answer += s.size();

			s.push(cow[i]);
		}

 		else // 소가 크면  
		{
			while (!s.empty() && s.top() <= cow[i]) //소가 안클때 까지 
			{
				s.pop();
				//if (s.empty()) 
				//{
				//	s.push(cow[i]);
				//	break;
				//}
			}
			answer += s.size();
			s.push(cow[i]);



		}



	}

	cout << answer;
	

	return 0;

}