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
	// ���� �ʱ�ȭ 
	stack<int> s;

	int answer = 0;

	for (int i = 0; i < N; i++)
	{
		if (s.empty())
		{
			s.push(cow[i]);
			continue;
		}

		if (s.top() > cow[i]) // �Ǿտ����� �Ұ� ������ 
		{
			
			answer += s.size();

			s.push(cow[i]);
		}

 		else // �Ұ� ũ��  
		{
			while (!s.empty() && s.top() <= cow[i]) //�Ұ� ��Ŭ�� ���� 
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