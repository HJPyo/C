#include<stdio.h>

int main(){
	int n, m, k;
	scanf("%1d %1d", &n, &m);
	k = m*10 + n;
	k *= 2;
	printf("%d\n", k/100);
	printf(k > 50 ? "OH MY GOD" : "GOOD");
}
