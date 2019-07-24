#include<iostream>

using namespace std;



int main() {

	int N; // ¹è¼ö 
	int sum = 0;
	int i = 1;
	
	cin >> N; 

	while (sum < 10000)
	{
		
		sum += N*i;
		i++;

	}
	
	cout << N*(i-2);





}