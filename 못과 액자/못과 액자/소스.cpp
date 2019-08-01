#include <stdio.h>
typedef struct {
	int r, c;
}PIN;
PIN pin[5];//��
typedef struct {
	int w, h;
}PIC;
PIC pic[5];//����
int pic_rec[5];//�ɺ� ���� ���
int dir_rec[5];//���ں� ���� ���
int chk[5];//���� üũ
int map[110][110];
int N, max;
int area_calc(void) {
	int i, j, k, cnt = 0, h, w, sr, sc, no;
	for (k = 1; k <= N; k++) {//��
		no = pic_rec[k];//������ڸ��� �� ����
		if (dir_rec[no] == 1) {//���ι���
			w = pic[no].w;
			h = pic[no].h;
		}
		else {//���ι���
			w = pic[no].h;
			h = pic[no].w;
		}
		sr = pin[k].r;
		sc = pin[k].c - w / 2;
		for (i = sr; i < sr + h; i++) {
			for (j = sc; j < sc + w; j++) {
				map[i][j] = 1;
			}
		}
	}
	//���� ���
	for (i = 0; i <= 100; i++) {
		for (j = 0; j <= 100; j++) {
			cnt += map[i][j];
			map[i][j] = 0;//�ʱ�ȭ
		}
	}
	return cnt;
}
void DFS(int p) {//���� ���ڸ��� 1~N���ڱ��� ������ ����Ͽ� �ɾ�� ���
	if (p > N) {
		int area = area_calc();
		if (area > max) max = area;
		return;
	}
	for (int i = 1; i <= N; i++) {//����
		if (chk[i] == 1) continue;
		chk[i] = 1; //���� üũ
		pic_rec[p] = i;
		dir_rec[i] = 1;//���ι���ɱ�
		DFS(p + 1);//���� ������
		dir_rec[i] = 2;//���ι���ɱ�
		DFS(p + 1);//���� ������
		chk[i] = 0;//���� ����
	}
}
int main(void) {
	int i;
	scanf("%d", &N);
	for (i = 1; i <= N; i++)scanf("%d %d", &pin[i].c, &pin[i].r);
	for (i = 1; i <= N; i++)scanf("%d %d", &pic[i].w, &pic[i].h);
	max = 0;
	DFS(1);//1�� ������ ����
	printf("%d", max);
	return 0;
}