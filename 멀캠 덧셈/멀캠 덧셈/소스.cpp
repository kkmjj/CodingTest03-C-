#include<iostream>
#include<string>
#include<math.h>
using namespace std;


int main() {
	// '1' -> 49
	string a;
	cin >> a; // 입력
	int answer = 0;
	cin >> answer;
	bool v = true;

	
	for (int i = 1; i < a.size(); i++) // + 위치 i=1 -> [1]뒤에 

	{
		int front = 0;
		int back = 0;
		int fcnt = 0;
		int bcnt = 0;

		for (int f = i; f >0; f--)
		{
			front += (a.at(f - 1) - 48) * pow(10, fcnt);
			fcnt++;

		}

		for (int j = i; j < a.size(); j++)
		{
			back += (a.at(j) - 48) * pow(10, a.size()-j);
		

		}
		back /= 10;
		cout << front << "+" << back << "=" << answer;
		cout << endl;
		cout << front + back;
		cout << endl;
		

		if (front + back == answer)
		{
			v = false;
		
			cout << front << "+" << back << "=" << answer;
			break;
		}


	}

	if (v) cout << "NONE";



}