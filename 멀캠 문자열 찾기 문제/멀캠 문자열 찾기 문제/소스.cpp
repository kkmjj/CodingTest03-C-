#include<iostream>
#include<string>
using namespace std;


int main() {

	string a = "ABCDEF";
	
	cin >> a;
	string temp;
	string k = "KOI";
	string i = "IOI";
	int koi = 0;
	int ioi = 0;

	for (int index = 0; index <=a.size() - 3; index++)
	{
		temp = a.substr(index, 3);
		if (temp == k)koi++;
		if (temp == i)ioi++;
		

	}

	cout << koi;
	cout << endl;
	cout << ioi;








}