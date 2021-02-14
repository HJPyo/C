#include <stdio.h>

int nx, ny, ar[12][12];

int main()
{
	for(int i = 1; i <= 10; i++){
		for(int j = 1; j <= 10; j++){
			scanf("%d", &ar[i][j]);
		}
	}
	
	nx = ny = 2;
	
	while(ar[nx][ny] != 2){
		ar[nx][ny] = 9;
		if(ar[nx][ny+1] != 1 && nx <= 10){
			ny++;
		}
		else if(ar[nx+1][ny] != 1 && ny <= 10){
			nx++;
		}
		else{
			break;
		}
	}
	ar[nx][ny] = 9;
	
	for(int i = 1; i <= 10; i++){
		for(int j = 1; j <= 10; j++){
			printf("%d ", ar[i][j]);
		}
		puts("");
	}
}
