#include<iostream>
#include<math.h>
using namespace std;


int N;
int chu[13];


int C;
int cu[8];
int temp[13];
bool answer;
int sub_a;
int sum_a;

void dfs(int cur,int left,int right)
{
	
	if (cur >= N)
	{
		
			for (int i = 0; i < cur; i++)
			{
				if (left == right)
				{
					answer = true;
					return;
				}
			
			}
		
		
		return;
	}




	temp[cur] = chu[cur];
	dfs(cur + 1,left+temp[cur],right);  //3번 왼쪽에 추 올려 놓을때 /오른쪽에 올려 놓을때 / 안올려 놓을때 
	
	dfs(cur + 1,left,right+temp[cur]);  
	
	temp[cur] = 0;	//	아무 것도 안둘때 
	dfs(cur + 1, left, right);




}


int main() {

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> chu[i];
	}
	// 추 
	cin >> C;
	for (int i = 0; i < C; i++)
	{
		answer = false;
		cin >> cu[i];
		dfs(0,cu[i],0); /// 추,왼쪽구술,오른쪽 

		if (answer)cout << "Y";
		else cout << "N";

		cout << " ";

	}
	// 구슬 

	













}