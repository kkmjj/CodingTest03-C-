#include<iostream>
using namespace std;

int N, M; // �迭�� ���� , ã�µ����� ���� 
int arr[50001];


int Binarysearch(int start, int e, int data)
{

	int m;
	while (start <= e)
	{
		 m= (e + start) / 2;

		if (arr[m] == data)return m+1; // �߾ӿ� �ִ°��� ã�µ����͸� return

		else if (arr[m] < data) // ã�����ϴ� �����Ͱ� �� ũ�� �����ʿ��� 
		{
			start = m + 1;
	
		}
		else			// ã�����ϴµ����Ͱ� �� ������ ������ 
		{
			e = m - 1;
		}


	}

	return 0;








}



int main() {

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
	// �Է� 

	cin >> M;
	for (int i = 0; i < M; i++)
	{
		int data;
		cin >> data; // ã�����ϴ� ������ 

	
		cout << Binarysearch(0, N - 1,data);
		cout << endl;

		}
















	}




