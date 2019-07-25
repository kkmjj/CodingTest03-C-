#include<iostream>
#include<string>
#include<math.h>
#include<algorithm>


using namespace std;

int arr[28];
int N;
int K;

int ten(string a)// 변에 있는 문자열 들어옴 
{
	int answer = 0;

	int index = (N/4)-1;
	for (int n = 0; n<a.size(); n++)
	{	if (a.at(n) >= 'A'&&a.at(n) <= 'F') // 10 ~16 // A -> 65 
		{
			answer += (a.at(n)- 55)*pow(16, index);

		}
		else //1~9
		{
			answer += (a.at(n) - 48)*pow(16, index);

		}
	index--;

	}

	return answer;

}



int main() {


	

	string input;

	cin >> N >> K;
	cin >> input;
	// 입력 

	int cnt = N / 4; // 회전수  

	
	int index = 0;

	 for (int i = 0; i < cnt; i++)
	{
		
		 arr[index] = ten(input.substr(0, cnt));
		 index++;
		 arr[index] = ten(input.substr(cnt, cnt));
		 index++;
		 arr[index] = ten(input.substr(cnt*2, cnt));
		 index++;
		 arr[index] = ten(input.substr(cnt*3, cnt));
		 index++;
		 // 값들 저장 

		 //회전 
		 string end = input.substr(input.size() - 1, 1);
		 input.erase(input.size()-1, 1);
		 input.insert(0, end);


	}

	 sort(arr, arr + input.size());
	 int max = arr[input.size()-1];
	 int count = 1;
	 for (int i = input.size() - 1; i >= 0; i--)
	 {
		 cout << arr[i] << " ";
	 }

	 cout << endl;

	 for (int i = input.size()-1; i >=0; i--)
	 {
		 if (max == arr[i])continue;
		
		 count++;
		 max = arr[i];
		 cout << arr[i] << " " << count;
		 cout << endl;
		if (count == K)cout << arr[i];

	 }





	












}