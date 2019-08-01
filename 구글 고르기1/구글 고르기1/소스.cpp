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


	if (no >=N) // DEPTH끝에 오면 출력 
	{
		
		return;
	}

	// 조합은 DFS2번으로 하는 구조 
	

	b[cnt] = a[no]; // b에 담기 
	DFS(no + 1,cnt+1);// 다음 구슬로 넘기기
	b[cnt] = 0;//담지 않고 
	DFS(no + 1,cnt);// 다음 구슬로 넘기기



}

int main() {

	DFS(0,0);


}