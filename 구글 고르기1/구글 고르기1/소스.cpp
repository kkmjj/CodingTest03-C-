#include<iostream>
using namespace std;

int a[3] = { 2,5,7 };
int b[3];
int N = 3;

void DFS(int no,int cnt)
{
	if (cnt == 2)
	{
		for (int i = 0; i < cnt; i++)
		{
			cout << b[i] << " ";

		}
		cout << endl;
		return;
	}


	if (no >=N) // DEPTH���� ���� ��� 
	{
		
		return;
	}

	// ������ DFS2������ �ϴ� ���� 
	

	b[cnt] = a[no]; // b�� ��� 
	DFS(no + 1,cnt+1);// ���� ������ �ѱ��
	b[cnt] = 0;//���� �ʰ� 
	DFS(no + 1,cnt);// ���� ������ �ѱ��



}

int main() {

	DFS(0,0);


}