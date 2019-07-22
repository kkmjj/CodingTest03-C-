#include <iostream>
#include <queue>
using namespace std;


int N;
int text;
int pick;
int priority;
int count = 0;

int ans[1000];
int cnt[10];


int main()
{

	cin >> N;

	for (int i = 0; i < N; i++) // testcase��ŭ 
	{
		int answer = 0;
		int max = 9;
		queue<int> q;

		cin >> text >> pick; // ���� ������ �ñ��� ���� 


		for (int j = 0; j < text; j++)
		{
			cin >> priority;
			q.push(priority);
			cnt[priority]++;
			
		}
	
		

		while (!q.empty())
		{
			int temp = q.front();

			if (cnt[max] == 0) // ���� �ִ밪�� �������� ������ ���� �ִ밪
			{
				max--;
				continue;
			}

			else  // �ִ밪�� �����ϸ� 
			{
				if (temp == max) // ó�� ���� max�̸� 
				{
					
					if (pick == 0) // �ش� ��ġ�̸� 
					{
						while (!q.empty()) q.pop();
						answer++;
						break;
					}

					q.pop();
					pick--;
					cnt[max]--;
					answer++;
					
					if (pick<0)pick = q.size() - 1;
					

					

				}
				else // ó�� ���� max�� �ƴϸ� 
				{
					q.pop();
					q.push(temp);
					pick--;
					if (pick<0)pick = q.size() - 1;
					

				}

			}


		}
		
		
		ans[i] = answer;

	}

	for (int i = 0; i < N; i++)
	{
		cout << ans[i] << endl;
	}





}