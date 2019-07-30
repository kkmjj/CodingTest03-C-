#include<iostream>

using namespace std;

int N, L, M;


struct m {
	int x;
	int y;
}m[100];


int main() {

	int xmin = 10000;
	int xmax = 0;
	int ymin = 10000;
	int ymax = 0;

	cin >> N >> L >> M; // 모눈종이 길이 , 그물길이, 물고기수 

	for (int i = 0; i < M; i++)
	{
		
		cin >> m[i].y >> m[i].x;

	}

	

	// 물고기가 있는 X좌표/Y좌표 의 최소 최대 다 쳐보기 


// L/2 ->(1,L/2-1)
	int answer = 0;
	int count = 0;

	for (int h = 1; h < L / 2; h++) // 그물 
	{
		int row = h;
		int col = (L / 2 - h);
		
		for (int i = 0; i <M; i++) //y좌표 
		{
			for (int j = 0; j <M; j++) // x좌표 
			{
				count = 0;
				for (int k = 0; k < M; k++)
				{
					

					if (m[k].y>=m[i].y && m[k].y<=m[i].y+row && 
						m[k].x>=m[j].x && m[k].x<=m[j].x+col)					// 물고기가 범위 안에 있으면 
					{
						count++;
					}


				}
				answer = answer < count ? count : answer;


			}

		}

			
	}


	cout << answer;





}