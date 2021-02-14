#include<stdio.h>
#include<algorithm>
using namespace std;

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
	tmp[x] = ar[y];
	for(int i = 0; i < n; i++){
		f(x+1,i);
	}
}

int main()
{
	scanf("%d %d", &n, &m);
	for(int i = 0; i < n; i++){
		scanf("%d", &ar[i]);
	}
	
	sort(ar,ar+n);
	
	for(int i = 0; i < n; i++){
		f(0,i);
	}
}
