


#include <stdio.h>



int N;

int a[30000 + 10];


void Qsort(int s, int e)
{
	int p, l, t, temp;
	if (s >= e)return;
	p = e; // 기준을 오른쪽 맨 끝요소 
	t = s; // 교환위치는 왼쪽 시작위치 
	for (l = s; l < e; l++) // 비교는 left와 pivot
	{
		if (a[l] < a[p]) // 맨왼쪽인 pivot보다 작으면 
		{
			temp = a[l];
			a[l] = a[t];
			a[t] = temp;
			t++;		// 교환후 target하나 오른쪽으로 이동 
		}
	}
	temp = a[p];
	a[p] = a[t];
	a[t] = temp; // 끝나고나서 pivot과 target을 교환 
	Qsort(s, t - 1); // 정렬된후 target기준 왼쪽은 작은수 target오른쪽은 큰수가 된다 .그 왼쪽을 다시 정렬
	Qsort(t+1, e); // 오른쪽을 다시 정렬 

}


int main(void)

{

	int i;



	// 입력받는 부분

	scanf("%d", &N);

	for (i = 0; i<N; i++)

	{

		scanf("%d", &a[i]);

	}



	Qsort(0, N - 1);



	for (i = 0; i<N; i++)

	{
		printf("%d", a[i]);

	}



	return 0;

}


