#include<stdio.h>

int n, ar[2][1000001], flag = 0;

void f(int x, int y, int val, int cnt)
{
	if(cnt == n){
		flag = 1;
		return;
	}
	if(ar[0][x] == ar[1][y]) f((x+1)%n,(y+n+val)%n,val,cnt+1);
	else return;
}

int main()
{
	scanf("%d", &n);
	
	for(int i = 0; i < 2; i++){
		for(int j = 0; j < n; j++){
			scanf("%d", &ar[i][j]);
		}
	}
	
	int P1 = 0, P2 = 0;
	while(ar[0][P1] != ar[1][P2])P2++;
	
	f(P1,P2,1,0);
	f(P1,P2,-1,0);
	
	printf("%s\n", flag ? "good puzzle" : "bad puzzle");
}
