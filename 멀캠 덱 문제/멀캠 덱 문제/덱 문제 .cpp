#include <deque>
#include <iostream>
using namespace std;




int main()
{

	deque<int> d;

	int N;
	cin >> N;
	// ���� �Է� 
	

	for (int i = N; i >= 1; i--)
	{
		d.push_back(i);
	}
	// �־��ְ� 
	int temp = 0;

	while (!d.empty())
	{
		int cnt = (d.front() / 2);


		for (int i = 0; i<cnt; i++)// ó�� 2�� ���� �� ��ŭ ������ 
		{
			
		
			int temp = d.back();
			d.pop_back(); // ������ ���Ҹ� temp�� �ְ� ������� 
			d.push_front(temp);// temp�� �ִ´� 
			
		}

	
		
			cout <<  d.back() << " ";
			d.pop_back();


	}

}