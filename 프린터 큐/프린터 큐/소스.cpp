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

	for (int i = 0; i < N; i++) // testcase만큼 
	{
		int answer = 0;
		int max = 9;
		queue<int> q;

		cin >> text >> pick; // 문서 개수와 궁금한 문서 


		for (int j = 0; j < text; j++)
		{
			cin >> priority;
			q.push(priority);
			cnt[priority]++;
			
		}
	
		

		while (!q.empty())
		{
			int temp = q.front();

			if (cnt[max] == 0) // 현재 최대값이 존재하지 않으면 다음 최대값
			{
				max--;
				continue;
			}

			else  // 최대값이 존재하면 
			{
				if (temp == max) // 처음 값이 max이면 
				{
					
					if (pick == 0) // 해당 위치이면 
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
				else // 처음 값이 max가 아니면 
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