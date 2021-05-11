#include<stdio.h>
#define YAS 5005

int ar[YAS<<1][YAS<<1], MAX = (YAS<<1) * (YAS<<1);
int dx[4] = {0,-1,0,1}, dy[4] = {1,0,-1,0};

int main(){
	ar[YAS][YAS] = 1;
	
	int x = YAS;
	int y = YAS;
	int dir = 0;
	
	for(int i = 2; i < YAS; i++){
		if(ar[x+dx[dir]][y+dy[dir]] != 0){
			dir++;
		}
		x += dx[dir];
		y += dy[dir];
		ar[x][y] = i;
	}
	
	for(int i = 4990; i <= 5010; i++){
		for(int j = 4990; j <= 5010; j++){
			printf("%d ", ar[i][j]);
		}
		puts("");
	}
}
