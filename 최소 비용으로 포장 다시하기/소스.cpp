#include<iostream>
using namespace std;
#define	MAX 5000
int N;
int arr[MAX+2];
int last=0;

int Enqueue(int d)
{
	int n, p, temp;
	if (last == MAX)return 0;

	arr[++last] = d;
	n = last; p = n / 2;
	while (p > 0)
	{
		if (arr[n] < arr[p])
		{
			temp = arr[n];
			arr[n] = arr[p];
			arr[p] = temp;
			n = p;
			p = n / 2;

		}
		else break;
	}
	return 1;
}


int Dequeue(int *d)
{
	int n, l, r, c, temp;
	if (last == 0) return 0;
	*d = arr[1];
	arr[1] = arr[last--];
	n = 1; l = 2; r = 3;
	while (l <= last)
	{
		if (l == last) c = l;
		else c = (arr[l] < arr[r]) ? l : r;
		if (arr[n] > arr[c])
		{
			temp = arr[n];
			arr[n] = arr[c];
			arr[c] = temp;
			n = c; l = n * 2; r = l + 1;

		}
		else break;
	}
	return 1;
}


int main() {
	cin >> N;
	int answer = 0;
	int sum;
	for (int i = 0; i < N; i++)
	{
		int data;
		cin >> data;
		Enqueue(data);  // 삽입
	}

	for (int i = 0; i < N-1; i++)
	{
		int first, second; // 두개씩 포장 
		Dequeue(&first);
		Dequeue(&second);
		sum = first + second;
		answer += sum;
		Enqueue(sum);
	}

	cout << answer;







}