#include<iostream>

using namespace std;
int n;
int cur = 0;

int sum(int start)
{
	cur += start;
	if (start == n)return cur;
	
	return  sum(start+1);

}

int main() {

	cin >> n;


	cout << sum(1);


}