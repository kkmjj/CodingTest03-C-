#include <deque>
#include <iostream>
using namespace std;




int main()
{

	deque<int> d;

	int N;
	cin >> N;
	// 문제 입력 
	

	for (int i = N; i >= 1; i--)
	{
		d.push_back(i);
	}
	// 넣어주고 
	int temp = 0;

	while (!d.empty())
	{
		int cnt = (d.front() / 2);


		for (int i = 0; i<cnt; i++)// 처음 2로 나눈 몫 만큼 돌리기 
		{
			
		
			int temp = d.back();
			d.pop_back(); // 마지막 원소를 temp에 넣고 지운다음 
			d.push_front(temp);// temp를 넣는다 
			
		}

	
		
			cout <<  d.back() << " ";
			d.pop_back();


	}

}