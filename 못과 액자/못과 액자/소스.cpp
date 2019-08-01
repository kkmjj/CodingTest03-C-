#include <stdio.h>
typedef struct {
	int r, c;
}PIN;
PIN pin[5];//못
typedef struct {
	int w, h;
}PIC;
PIC pic[5];//액자
int pic_rec[5];//핀별 액자 기록
int dir_rec[5];//액자별 방향 기록
int chk[5];//액자 체크
int map[110][110];
int N, max;
int area_calc(void) {
	int i, j, k, cnt = 0, h, w, sr, sc, no;
	for (k = 1; k <= N; k++) {//못
		no = pic_rec[k];//현재못자리에 건 액자
		if (dir_rec[no] == 1) {//가로방향
			w = pic[no].w;
			h = pic[no].h;
		}
		else {//세로방향
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
	//면적 계산
	for (i = 0; i <= 100; i++) {
		for (j = 0; j <= 100; j++) {
			cnt += map[i][j];
			map[i][j] = 0;//초기화
		}
	}
	return cnt;
}
void DFS(int p) {//현재 못자리에 1~N액자까지 순서를 고려하여 걸어보는 경우
	if (p > N) {
		int area = area_calc();
		if (area > max) max = area;
		return;
	}
	for (int i = 1; i <= N; i++) {//액자
		if (chk[i] == 1) continue;
		chk[i] = 1; //액자 체크
		pic_rec[p] = i;
		dir_rec[i] = 1;//가로방향걸기
		DFS(p + 1);//다음 못으로
		dir_rec[i] = 2;//세로방향걸기
		DFS(p + 1);//다음 못으로
		chk[i] = 0;//액자 해제
	}
}
int main(void) {
	int i;
	scanf("%d", &N);
	for (i = 1; i <= N; i++)scanf("%d %d", &pin[i].c, &pin[i].r);
	for (i = 1; i <= N; i++)scanf("%d %d", &pic[i].w, &pic[i].h);
	max = 0;
	DFS(1);//1번 못부터 시작
	printf("%d", max);
	return 0;
}