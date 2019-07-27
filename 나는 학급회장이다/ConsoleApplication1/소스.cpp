/*
문제 설명

N명의 학생들이 모인 초등학교 반에서 학급회장 선거를 하려고 한다. 그 중 3명이 회장후보로 나왔고,
이들에 대한 선호도를 N명의 학생들 각각에게 적어내도록 하였다. 세 명의 후보는 후보 1번, 후보 2번, 후보 3번이라 한다.

모든 학생은 3명의 후보 중에서 가장 선호하는 후보에게는 3점, 두 번째로 선호하는 후보에게는 2점, 
가장 선호하지 않는 후보에게는 1점을 주어야 한다. 3명의 후보에 대한 한 학생의 선호 점수는 모두 다르며, 1점, 2점, 3점이 정확히 한 번씩 나타나야 한다.

후보의 최종 점수는 학생들로부터 받은 자신의 선호도 점수를 모두 더한 값이 된다. 그러면 3명의 후보 중 
가장 큰 점수를 받은 후보가 회장으로 결정된다. 단, 점수가 가장 큰 후보가 여러 명인 경우에는 3점을 더 많이 받은 후보를 회장으로 결정하고, 3점을 받은 횟수가 같은 경우에는 2점을 더 많이 받은 후보를 회장으로 결정한다. 그러나 3점과 2점을 받은 횟수가 모두 동일하면, 1점을 받은 횟수도 같을 수밖에 없어 회장을 결정하지 못하게 된다.

여러분은 선호도 투표를 통해 얻은 세 후보의 점수를 계산한 후, 유일하게 회장이 결정되는 경우에는 회장으로 
결정된 후보의 번호(1, 2, 3 중 한 번호)와 최고 점수를 출력하고, 회장을 결정하지 못하는 경우에는 번호 0과 최고 점수를 출력하는 프로그램을 작성하시오.
*/

#include<iostream>
using namespace std;



struct student
{
	int three=0;
	int two=0;
	int sum = 0;

}student[4];


int vote[1000][4];
bool same = false;

int compare(int front,int back )
{

	if (student[front].sum < student[back].sum) //큰 인덱스 값 
	{
		if (same)same = false; // 앞에서 같았지만 뒤에서 더 큰숫자가 나오면 

		return back;
	}

	else if (student[front].sum > student[back].sum)
	{
		if (same) return 0; // // 앞에서 같았는데 뒤에서 작은 값이 나오면 0

		return front;
	}

	else if (student[front].sum == student[back].sum) // 합이 같음 
	{

		if (student[front].three < student[back].three) //큰 인덱스 값 
		{
			return back;
		}

		else if (student[front].three > student[back].three)
		{
			return front;
		}
		else if (student[front].three == student[back].three) // three 마저도 같음 
		{
			if (same) return 0; // 셋다 같을 경우 
			same = true;
			return front; // 둘중 아무거나 리턴
		}

	}


}





int main() {

	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
	{

		for (int j = 1; j <= 3; j++) // 각 학생에 대해서 후보 3명 투표 
		{

			cin >> vote[i][j];
			if (vote[i][j] == 3)
			{
				student[j].three++;
			}
			if (vote[i][j] == 2)
			{
				student[j].two++;
			}
		}
	}
	// 입력 
	int index = 0;
	int answer = 0;

	for (int j = 1; j <= 3; j++)
	{

		for (int i = 0; i < N; i++)
		{

			student[j].sum += vote[i][j];

		}
		answer = answer < student[j].sum ? student[j].sum : answer;
	}



	// 비교 
	index=compare(1, 2);
	index = compare(index, 3);

	cout << index << " " << answer;


}