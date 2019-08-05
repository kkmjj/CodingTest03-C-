


#include <stdio.h>



int N;

int a[30000 + 10];
int temp[30000 + 10];

void Mergesort(int s, int e)
{
	int m = e / 2; // �������� �ɰ��� 
	int i;
	int j;
	int k;
	if (s >= e)return; // 1�� ���ϰ� �Ǹ� ���� 


	Mergesort(s, m); // ������ �ٽ� �ɰ���
	Mergesort(m + 1, e); // ���� �ٽ� �ɰ� 
	
	i = s; // ���� ���� ���� 
	j = m + 1; // ������ ���� ���� 
	k = s;  // �ӽ� ���� ����

	// ���� �� ������ ������ ���Ͽ� ���� ���� �ӽù��ۿ� ���� 
	// ���ʰ� ������ ������ ���� ������ �ӽù��ۿ� ���� 
	// �ν� ���۸� �����迭�� ���� 
	while(i<=m && j<=e){

		if (a[i] < a[j]) // ���� ���ذ� ������ ���� ���ؼ� ������ ������ ������ ��´�.
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
	// ���� �Ǵ� ������ �� �� ������� �Ǹ� ������ ���� ���� ���� 
	while (i <= m)temp[k++] = a[i++];
	while (j <= e)temp[k++] = a[j++];

	for (int i = s; i <= e; i++) a[i] = temp[i];





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



	Mergesort(0, N - 1);



	for (i = 0; i<N; i++)

	{
		printf("%d", a[i]);

	}



	return 0;

}


