#include<iostream>
// dfs ���� ����  �ߺ� ��� �Ұ� �� dfs 
using namespace std;


int a[3] = { 2,5,7 };
int b[3];
int chk[3];
int N = 3;

void DFS(int no)
{
	if (no==3)
	{
		for (int i = 0; i < 3; i++)
		{
			cout << b[i]<< " ";
		}
		cout << endl;
	}
	

	for (int i = 0; i < 3; i++)
	{
		if (chk[i])continue;
		chk[i] = 1; // a[no] �� üũ �ƴٰ� üũ 
		b[no] = a[i];
		DFS(no + 1);
		chk[i] = 0;


	}
	





}

int main() {

	DFS(0);




}