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
	dfs(cur + 1,left+temp[cur],right);  //3�� ���ʿ� �� �÷� ������ /�����ʿ� �÷� ������ / �ȿ÷� ������ 
	
	dfs(cur + 1,left,right+temp[cur]);  
	
	temp[cur] = 0;	//	�ƹ� �͵� �ȵѶ� 
	dfs(cur + 1, left, right);




}


int main() {

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> chu[i];
	}
	// �� 
	cin >> C;
	for (int i = 0; i < C; i++)
	{
		answer = false;
		cin >> cu[i];
		dfs(0,cu[i],0); /// ��,���ʱ���,������ 

		if (answer)cout << "Y";
		else cout << "N";

		cout << " ";

	}
	// ���� 

	













}