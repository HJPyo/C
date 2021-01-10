#include<stdio.h>
#include<algorithm>
using namespace std;

int n, m, ar[100001];

bool f(int L, int R, int x)
{
	int M = (L+R)/2;
	if(ar[M] == x) return true;
	if(L<R){
		if(ar[M] > x) return f(L, M, x);
		else return f(M+1, R, x);
	}
	return false;
}

int main()
{
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
	scanf("%d", &ar[i]);
	sort(ar,ar+n);
	
	scanf("%d", &m);
	while(m--){
		int o;
		scanf("%d", &o);
		if(f(0,n-1,o)) puts("1");
		else puts("0");
	}
}
