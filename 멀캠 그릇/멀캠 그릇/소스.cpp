#include<iostream>
#include<string>

using namespace std;


int main() {

	string a;

	cin >> a; // �Է� 


	char temp = a.at(0); // ó�� �κ� ���� 
	int answer = 10;

	for (int i = 1; i < a.size(); i++)
	{
		if (a.at(i) == temp) // ������ 5�� ���ϰ� 
		{
			answer += 5;
			temp = a.at(i);
		}
		else // �ٸ��� 
		{
			temp = a.at(i);
			answer += 10;

		}



	}

	cout << answer;






}