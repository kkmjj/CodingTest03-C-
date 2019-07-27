/*
���� ����

N���� �л����� ���� �ʵ��б� �ݿ��� �б�ȸ�� ���Ÿ� �Ϸ��� �Ѵ�. �� �� 3���� ȸ���ĺ��� ���԰�,
�̵鿡 ���� ��ȣ���� N���� �л��� �������� ������� �Ͽ���. �� ���� �ĺ��� �ĺ� 1��, �ĺ� 2��, �ĺ� 3���̶� �Ѵ�.

��� �л��� 3���� �ĺ� �߿��� ���� ��ȣ�ϴ� �ĺ����Դ� 3��, �� ��°�� ��ȣ�ϴ� �ĺ����Դ� 2��, 
���� ��ȣ���� �ʴ� �ĺ����Դ� 1���� �־�� �Ѵ�. 3���� �ĺ��� ���� �� �л��� ��ȣ ������ ��� �ٸ���, 1��, 2��, 3���� ��Ȯ�� �� ���� ��Ÿ���� �Ѵ�.

�ĺ��� ���� ������ �л���κ��� ���� �ڽ��� ��ȣ�� ������ ��� ���� ���� �ȴ�. �׷��� 3���� �ĺ� �� 
���� ū ������ ���� �ĺ��� ȸ������ �����ȴ�. ��, ������ ���� ū �ĺ��� ���� ���� ��쿡�� 3���� �� ���� ���� �ĺ��� ȸ������ �����ϰ�, 3���� ���� Ƚ���� ���� ��쿡�� 2���� �� ���� ���� �ĺ��� ȸ������ �����Ѵ�. �׷��� 3���� 2���� ���� Ƚ���� ��� �����ϸ�, 1���� ���� Ƚ���� ���� ���ۿ� ���� ȸ���� �������� ���ϰ� �ȴ�.

�������� ��ȣ�� ��ǥ�� ���� ���� �� �ĺ��� ������ ����� ��, �����ϰ� ȸ���� �����Ǵ� ��쿡�� ȸ������ 
������ �ĺ��� ��ȣ(1, 2, 3 �� �� ��ȣ)�� �ְ� ������ ����ϰ�, ȸ���� �������� ���ϴ� ��쿡�� ��ȣ 0�� �ְ� ������ ����ϴ� ���α׷��� �ۼ��Ͻÿ�.
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

	if (student[front].sum < student[back].sum) //ū �ε��� �� 
	{
		if (same)same = false; // �տ��� �������� �ڿ��� �� ū���ڰ� ������ 

		return back;
	}

	else if (student[front].sum > student[back].sum)
	{
		if (same) return 0; // // �տ��� ���Ҵµ� �ڿ��� ���� ���� ������ 0

		return front;
	}

	else if (student[front].sum == student[back].sum) // ���� ���� 
	{

		if (student[front].three < student[back].three) //ū �ε��� �� 
		{
			return back;
		}

		else if (student[front].three > student[back].three)
		{
			return front;
		}
		else if (student[front].three == student[back].three) // three ������ ���� 
		{
			if (same) return 0; // �´� ���� ��� 
			same = true;
			return front; // ���� �ƹ��ų� ����
		}

	}


}





int main() {

	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
	{

		for (int j = 1; j <= 3; j++) // �� �л��� ���ؼ� �ĺ� 3�� ��ǥ 
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
	// �Է� 
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



	// �� 
	index=compare(1, 2);
	index = compare(index, 3);

	cout << index << " " << answer;


}