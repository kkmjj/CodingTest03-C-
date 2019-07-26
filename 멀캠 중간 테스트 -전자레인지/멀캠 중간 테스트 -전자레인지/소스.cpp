#include<iostream>

using namespace std;
int arr[3];

int main() {

	int A = 300;
	int B = 60;
	int C = 10;

	int input;
	cin >> input;
	// ÀÔ·Â 

	

	arr[0] = input / A;

	input = input % A;

	arr[1] = input / B;

	input = input % B;

	arr[2] = input / C;

	input = input % C;

	if (input != 0) cout << -1;
	else
	{
		for (int i = 0; i < 3; i++)
		{
			cout << arr[i] << " ";
		}
	}









}