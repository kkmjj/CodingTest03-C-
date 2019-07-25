#include<iostream>

using namespace std;




int main() {

	char a[4];
	char b[4];

	for (int i = 0; i < 4; i++)
	{
		cin >> a[i];
	}
	for (int i = 0; i < 4; i++)
	{
		cin >> b[i];
	}
	// ют╥б 
	int front=0;
	int back=0;

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (i == j&&a[i] == b[j])front++;

			else if (i != j&&a[i] == b[j])back++;



		}
	}

	cout << front << "A" << back << "B";







}