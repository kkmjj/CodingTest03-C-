#include<iostream>
#include<string>
using namespace std;

int a[25];

int main() {

	
	string input;
	cin >> input;

	

	for (int i = 0; i < input.size(); i++)
	{
		if (input.at(i) >= 'a'&&input.at(i) <= 'z') //소문자이면 
		{
		
			int temp = (int)(input.at(i) - 97);
			a[temp]++;
			
		}
	}

	int max = 0;
	int answer = 0;


	for (int i = 0; i < 25; i++)
	{
		
	
		if (max < a[i]) {
			max = a[i];
			answer = i;
		

		}

	}

	cout << (char)(answer + 97);



}