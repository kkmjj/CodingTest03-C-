#include<stdio.h>
#include<stdlib.h>


typedef struct st {
	int data;
	struct st* prev;
}STACK;


STACK *sp;
int cnt=0;
int N;
int push(int d) 	{
	STACK *ne = calloc(1, sizeof(STACK));
	ne->data = d;
	ne->prev = sp; // �߰��� ���� ���� ���� ��ũ 
	sp = ne;	// ���ο� ����� �ּҰ� ������ ���� sp���� 
	cnt++;
	return 1;

}



int pop(STACK *d) {
	STACK *del = sp; // ������ ��� ��� 
	if (sp == NULL)return 0; // empty
	*d = *sp;
	sp = sp->prev; // ���� ���
	free(del);
	cnt--;
	return 1;
	

}







int main() {
	int i, cmd, data;
	STACK temp; // �ӽ� ���� �ּ� 
	scanf("%d", &N);
	
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &cmd);
		if (cmd == 1) 
		{
			scanf("%d", &data);
			//data�� Ǫ�� 
			push(data);
		}
		else if (cmd == 0)
		{ // ���ÿ��� �����͸� ���� , �� �����͸� ����Ѵ�.
			// ���� ������ ��� ������ 'E'�� ��� 
			if (pop(&temp)) printf("%d\n", temp.data);
			else printf("E\n");

		}
		else 
		{// ���ÿ� ���� ������ ��� 
			printf("%d\n", cnt);

		}
	}





}