#include<iostream>
#include<math.h>
using namespace std;


int one = 0, two = 0, three = 0, four = 0;
int answer[5][3];
int a[5];
void direction(int d,int h)
{
	if (d == 1) {
		one++;
		answer[1][one] = h;

	}
	else if (d == 2)
	{
		two++;
		answer[2][two] = h;
	}
	else if (d == 3)
	{
		three++;
		answer[3][three] = h;
	}
	
	else if (d == 4)
	{
		four++;
		answer[4][four] = h;
	}

}

int main() {


	int N;
	cin >> N;
	int start = 0;
	for (int i = 0; i < 6; i++)
	{
		int d;
		int h;
		cin >> d >> h;
		if (start == 0)start = d;
	
		direction(d,h);


	}

	int wide = 1; // 전체 넓이
	int subwide = 1; // 뺄 넓이
	
	
	for(int i=1;i<=4;i++)
	{  
		
		if (answer[i][2] == 0) // 방향이 한번만 있었을경우 
		{
			wide*=answer[i][1];
		}
		else
		{
			a[i] = 1;

		}

	[]
	}


	
		
	//왼쪽 아래 
	if (a[1] == 1 && a[3] == 1)
	{

	}

	





	cout << wide << " " << subwide;
	cout << endl;
	cout << (wide - subwide)*N;


}