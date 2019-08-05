


#include <stdio.h>



int N;

int a[30000 + 10];
int temp[30000 + 10];

void Mergesort(int s, int e)
{
	int m = e / 2; // 절반으로 쪼갠다 
	int i;
	int j;
	int k;
	if (s >= e)return; // 1개 이하가 되면 종료 


	Mergesort(s, m); // 오른쪽 다시 쪼개고
	Mergesort(m + 1, e); // 왼쪽 다시 쪼갬 
	
	i = s; // 왼쪽 영역 시작 
	j = m + 1; // 오른쪽 영역 시작 
	k = s;  // 임시 버퍼 시작

	// 왼쪽 과 오른쪽 영역을 비교하여 작은 값을 임시버퍼에 저장 
	// 왼쪽과 오른쪽 영역중 남은 영역을 임시버퍼에 저장 
	// 인시 버퍼를 원본배열에 복사 
	while(i<=m && j<=e){

		if (a[i] < a[j]) // 왼쪽 기준과 오른쪽 기준 비교해서 왼쪽이 작으면 왼쪽을 담는다.
		{
			temp[k] = a[i];
			i++;
			k++;
		}
		else
		{

			temp[k] = a[j];
			j++;
			k++;
		}


		}
	// 왼쪽 또는 오른쪽 이 다 담겨지게 되면 마지막 남은 것을 저장 
	while (i <= m)temp[k++] = a[i++];
	while (j <= e)temp[k++] = a[j++];

	for (int i = s; i <= e; i++) a[i] = temp[i];





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



	Mergesort(0, N - 1);



	for (i = 0; i<N; i++)

	{
		printf("%d", a[i]);

	}



	return 0;

}


