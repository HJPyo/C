#include<stdio.h>

int n, m, ar[19], cnt = 0;

void f(int x, int y)
{
	if(x > n) return;
	if(x == n){
		cnt++;
		if(cnt == m){
			printf("%d", ar[0]);
			for(int i = 1; i < y; i++){
				printf("+%d", ar[i]);
			}
		}
	}
	
	for(int i = 1; i < 4; i++){
		ar[y] = i;
		f(x+i, y+1);
		ar[y] = 0;
	}
}

int main()
{
	scanf("%d %d", &n, &m);
	f(0,0);
	if(cnt < m) puts("-1");
}
