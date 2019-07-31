#include<iostream>
#include<math.h>
using namespace std;



int main() {
	int arr[6];
	int h, d;
	int dmax = 0;
	int hmax = 0;
	int hindex = 0;
	int dindex = 0;
	int N;
	cin >> N;

	for (int i = 0; i < 6; i++)
	{
		
		
		cin >> d >> h;
		
		if (d == 4 || d == 3)
		{
			if (hmax < h)
			{
				hmax = h;
				hindex = i;
			}
		}
		if (d == 1 || d == 2)
		{
			if (dmax < h)
			{
				dmax = h;
				dindex = i;
			}
			
		}

		arr[i] = h;

	}

	int min_h;
	int min_w;


	min_h = arr[(hindex + 3)%6];
	min_w = arr[(dindex + 3)%6];

	cout << min_h << " " << min_w;
	cout << endl;
	cout << ((hmax*dmax) - (min_h*min_w))*N;

	
	



}