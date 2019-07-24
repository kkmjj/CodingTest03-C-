#include<iostream>
#include<algorithm>
#include<math.h>

using namespace std;




bool prime(int n)
{
	
	if (n == 1) return false;

	int end = (int)sqrt(n);

	for (int i = 2; i <= end; i++)
	{
		if ((n%i) == 0)
		{
			return false;
		}
	}


	return true;
}




int main()

{
	int a;
	int b;
	int index = 0;

	int arr[100000];
	cin >> a >> b;

	int max = a < b ? b : a;
	int min = a < b ? a : b; 


	for (int i = min; i <= max; i++)
	{
		if (prime(i)) {
			arr[index] = i;
			index++;
		}
	}
	

	sort(arr, arr + index);
	cout << index;
	cout << endl;

	cout << arr[index - 1] + arr[0];


}