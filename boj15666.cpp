#include<stdio.h>

int n, m, ar[10001], tmp[8];

void f(int x, int y)
{
	if(x == m){
		for(int i = 0; i < m; i++)
			printf("%d ", tmp[i]);
		puts("");
		return;
	}
	for(int i = y; i < 10001; i++){
		if(!ar[i]) continue;
		tmp[x] = i;
		f(x+1, i);
	}
}

int main()
{
	scanf("%d %d", &n, &m);
	for(int i = 0, j; i < n; i++){
		scanf("%d", &j);
		ar[j]++;
	}
	
	f(0,0);
}
