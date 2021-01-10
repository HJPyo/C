#include<stdio.h>

int arr[6666][6666];

void BOOM(int x, int y, int w)
{
	for(int i = x; i < x+w; i++){
		for(int j = y; j < y+w; j++){
			arr[i][j] = 1;
		}
	}
}

void f(int x, int y, int w)
{
	if(w == 3){	arr[x+1][y+1] = 1; return; }
	
	f(x,y,w/3);
	f(x,y+w/3,w/3);
	f(x,y+(w/3)*2,w/3);
	f(x+w/3,y,w/3);
	BOOM(x+w/3,y+w/3,w/3);
	f(x+w/3,y+(w/3)*2,w/3);
	f(x+(w/3)*2,y,w/3);
	f(x+(w/3)*2,y+w/3,w/3);
	f(x+(w/3)*2,y+(w/3)*2,w/3);
}

int main()
{
	int n;
	scanf("%d", &n);
	
	f(0,0,n);
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			printf("%c", arr[i][j] ? ' ' : '*');
		}
		puts("");
	}
}
