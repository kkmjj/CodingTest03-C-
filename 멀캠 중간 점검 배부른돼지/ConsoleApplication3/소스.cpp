#include<iostream>

using namespace std;

int arr[10];
int main() {
	bool v = true;
	int N; // 테스트 케이스 
	cin >> N;
	
	int number = 0;
	char m;
	for (int i = 0; i < N; i++)
	{
		
		cin >> number;
		cin >> m;

		if (m == 'N')
		{
			for (int i =number;i>0; i--)
			{
				if (arr[i] == 1)v = false;
				arr[i] = 2; // 2가 들어있으면  만족하지 못함 
			}

		}
		else if (m == 'Y')
		{
			
			
			for (int i = number; i <10; i++)
			{
				if (arr[i] == 2)v = false;
				arr[i] = 1;
			}

		}

	}

	if (!v||N==0)cout << "F";
	else
	{
		for (int i = 0; i < 10; i++)
		{
			if (arr[i]== 1) {
				cout << i;
				break;
			}

		}
	}






}