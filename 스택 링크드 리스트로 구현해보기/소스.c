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
	ne->prev = sp; // 추가할 노드는 이전 노드로 링크 
	sp = ne;	// 새로운 노드의 주소가 마지막 노드로 sp갱신 
	cnt++;
	return 1;

}



int pop(STACK *d) {
	STACK *del = sp; // 마지막 노드 백업 
	if (sp == NULL)return 0; // empty
	*d = *sp;
	sp = sp->prev; // 이전 노드
	free(del);
	cnt--;
	return 1;
	

}







int main() {
	int i, cmd, data;
	STACK temp; // 임시 변수 주소 
	scanf("%d", &N);
	
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &cmd);
		if (cmd == 1) 
		{
			scanf("%d", &data);
			//data를 푸쉬 
			push(data);
		}
		else if (cmd == 0)
		{ // 스택에서 데이터를 빼고 , 그 데이터를 출력한다.
			// 만약 스택이 비어 있으면 'E'를 출력 
			if (pop(&temp)) printf("%d\n", temp.data);
			else printf("E\n");

		}
		else 
		{// 스택에 쌓인 개수를 출력 
			printf("%d\n", cnt);

		}
	}





}