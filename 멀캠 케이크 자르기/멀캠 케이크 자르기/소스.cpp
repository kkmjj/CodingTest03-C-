#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main() 

{
	int first[2];
	int second[2];
	bool v = false;
	bool vs = false;


	for (int i = 0; i < 2; i++)
	{
		cin >> first[i];
	}
	for (int i = 0; i < 2; i++)
	{
		cin >> second[i];
	}

	sort(first, first + 2);
	
	if (second[0] >= first[0] && second[0] <= first[1])// 범위안이면 true
	{
		v = true;
	}
	
	if (second[1] >=first[0] && second[1] <=first[1])// 범위안이면 true
	{
		vs = true;
	}




	
	if (v&&vs|| !v&&!vs) cout << "not cross";
	
	else cout << "cross";
	




}