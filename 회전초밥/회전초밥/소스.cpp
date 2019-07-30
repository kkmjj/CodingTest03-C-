
#include<iostream>

using namespace std;

int p[3000001];

int visit[3001];


int main() {
	int entire; // 전체접시
	int s;  // 종류 
	int plate; // 사용접시 
	int coupon; // 쿠폰 

	cin >> entire >> s >> plate >> coupon;


	for (int i = 0; i < entire; i++)
	{
		cin >> p[i];
	}
	// 입력 

	for (int i = entire; i <entire+plate; i++)
	{
		p[i] = p[entire - i];
	}

	// 7 9 7 30 2 7 9 25     +    7 9 7 30 
 


	int max = 0;
	int type = 0;
	int temp = 0;

	for (int i = 0; i < plate; i++)
	{
	
		visit[p[i]]++;
		if (visit[p[i]] == 1)
		{
			
			type++;
		}
	}
	max = type;



	for (int k = 0; k < entire-1 ; k++)
	{
		int front = k;
		int back = plate + k;
			
		                         
			visit[front]--;
			if (visit[front] == 0)type--;

			if (visit[back] == 0)
			{
				type++;
				visit[back]++;
			}
			temp = type;
			if (visit[coupon] == 0) temp++;
			if (max < temp) max = temp;
			
			


		
		
	}


	cout << max;





}
