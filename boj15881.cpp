#include<stdio.h>

int n, ar[1001], com[1001], cnt = 0, mem[1001];

int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		scanf("%d", &ar[i]);
		if(ar[i] == i) com[i] = 1;
	}
	for(int i = 1; i <= n; i++){
		if(com[i] || ar[i] > n || com[ar[i]]) continue;
		mem[cnt] = ar[i]*10 + i;
		cnt++;
		int tmp = ar[i];
		ar[i] = ar[tmp];
		ar[tmp] = tmp;
		com[tmp] = 1;
	}
	printf("%d\n", cnt);
	for(int i = 0; i < cnt; i++)
	printf("%d %d\n", mem[i]%10, mem[i]/10);
}
