#include<iostream>

using namespace std;


int main() {

	char a;
	cin >> a;// 문자 입력 



	if (a >= 'a'&& a <= 'z')
	{
		for (int i = 0; i <= 25; i++)
		{
			cout << (char)('a' + i);

			if ((char)('a' + i) == a)break;

		}
	}
	else if(a >= 'A'&& a <= 'Z')
	{

		for (int i =0; i <= 25; i++)
		{
			cout << (char)(a + i);
			if ((char)(a + i) == 'Z') break;

		

		}




	}
	else cout << "Error";





}