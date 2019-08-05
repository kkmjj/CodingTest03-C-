


#include <stdio.h>



int N;

int a[30000 + 10];


void Qsort(int s, int e)
{
	int p, l, t, temp;
	if (s >= e)return;
	p = e; // ������ ������ �� ����� 
	t = s; // ��ȯ��ġ�� ���� ������ġ 
	for (l = s; l < e; l++) // �񱳴� left�� pivot
	{
		if (a[l] < a[p]) // �ǿ����� pivot���� ������ 
		{
			temp = a[l];
			a[l] = a[t];
			a[t] = temp;
			t++;		// ��ȯ�� target�ϳ� ���������� �̵� 
		}
	}
	temp = a[p];
	a[p] = a[t];
	a[t] = temp; // �������� pivot�� target�� ��ȯ 
	Qsort(s, t - 1); // ���ĵ��� target���� ������ ������ target�������� ū���� �ȴ� .�� ������ �ٽ� ����
	Qsort(t+1, e); // �������� �ٽ� ���� 

}


int main(void)

{

	int i;



	// �Է¹޴� �κ�

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


