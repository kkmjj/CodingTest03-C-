#include<iostream>
using namespace std;

// M=1 -> ��� ����Ǽ� M=2 ->���� ��� ���ϰ� �ߺ� �Ǵ°� ����   M=3 -> ��� �ٸ� ���� ������ ��� 
// M1 ���� /M2 �ߺ� ���� / M3 

int N;
int rec[10];
int check[10];

void dfs1(int cur) { // �⺻ �ߺ� ���� 
	
	
	if(cur >= N)
	{
		for (int i = 0; i < cur; i++)
		{
			cout << rec[i] <<" ";
		}
		cout << endl;
		return;
	}


	for (int i = 1; i <= 6; i++)
	{
		rec[cur] = i;
		dfs1(cur + 1);
	}


}

void dfs2(int cur,int start) { //���� �ߺ� ������ ���� 


	if (cur >= N)
	{
		for (int i = 0; i < cur; i++)
		{
			cout << rec[i] << " ";
		}
		cout << endl;
		return;
	}


	for (int i = start; i <= 6; i++)
	{
		rec[cur] = i;
		dfs2(cur + 1,i);
	}






}

void dfs3(int cur) { // ���� �ߺ� ������ ����

	if (cur >= N)
	{
		for (int i = 0; i < cur; i++)
		{
			cout << rec[i] << " ";
		}
		cout << endl;
		return;
	}


	for (int i = 1; i <= 6; i++)
	{
		if (check[i] == 1)continue;
		check[i] = 1;
		rec[cur] = i;
		dfs3(cur + 1);
		check[i] = 0;
	}



}

void dfs4(int cur,int start) { //���� �ߺ� ������ ���� 
	

	if (cur >= N)
	{
		for (int i = 0; i < cur; i++)
		{
			cout << rec[i] << " ";
		}
		cout << endl;
		return;
	}


	for (int i = start; i <= 6; i++)
	{
	
		rec[cur] = i;
		dfs4(cur + 1,i+1);

	}

}

int M;


int main() {


	cin >> N >> M;

	switch (M)
	{
	case 1:
		dfs1(0);
		break;
	case 2:
		dfs2(0,1);
		break;
	case 3:
		dfs3(0);
		break;
	default:
		break;
	}









}