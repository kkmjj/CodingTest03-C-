#include<iostream>
#include<string>

using namespace std;


int main() {

	string a;

	cin >> a; // 입력 


	char temp = a.at(0); // 처음 부분 저장 
	int answer = 10;

	for (int i = 1; i < a.size(); i++)
	{
		if (a.at(i) == temp) // 같으면 5를 더하고 
		{
			answer += 5;
			temp = a.at(i);
		}
		else // 다르면 
		{
			temp = a.at(i);
			answer += 10;

		}



	}

	cout << answer;






}