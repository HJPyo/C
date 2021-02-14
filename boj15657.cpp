#include<stdio.h>
#include<algorithm>

int n, m, ar[10], tmp[10];

void f(int x, int y)
{
	if(x == m){
		for(int i = 0; i < m; i++){
			printf("%d ", tmp[i]);
		}
		puts("");
		return;
	}
	for(int i = y; i < n; i++){
		tmp[x] = ar[i];
		f(x+1,i);
	}
}

int main()
{
	scanf("%d %d", &n, &m);
	for(int i = 0; i < n; i++){
		scanf("%d", &ar[i]);
	}
	std::sort(ar,ar+n);
	f(0,0);
}
