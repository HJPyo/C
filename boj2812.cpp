#include<stdio.h>
#define MAX 500005

int n, k;
struct num{ int idx, x; }ar[MAX], tmp[MAX];

int cmp(int a, int b, int flag)
{
	return flag ? ar[a].idx < ar[b].idx : ar[a].x < ar[b].x;
}

void merge(int L, int R, int M, int flag)
{
	int Gp = L;
	int Lp = L, Rp = M+1;
	int Lm = M, Rm = R;
	
	while(Lp <= Lm || Rp <= Rm){
		if(Lp > Lm){
			tmp[Gp++] = ar[Rp++];
		}
		else if(Rp > Rm){
			tmp[Gp++] = ar[Lp++];
		}
		else if(cmp(Lp, Rp, flag)){
			tmp[Gp++] = ar[Lp++];
		}
		else{
			tmp[Gp++] = ar[Rp++];
		}
	}
	
	for(int i = L; i <= R; i++){
		ar[i] = tmp[i];
	}
}

void sort(int L, int R, int flag)
{
	if(L < R){
		int M = (L+R) >> 1;
		sort(L, M, flag);
		sort(M+1, R, flag);
		merge(L, R, M, flag);
	}
}

int main()
{
	scanf("%d %d", &n, &k);
	
	for(int i = 0; i < n; i++){
		ar[i].idx = i;
		scanf("%1d", &ar[i].x);
	}
	
	sort(0, n-1, 0);
	
	for(int i = 0; i < k; i++){
		ar[i].x = -1;
	}
	
	sort(0, n-1, 1);
	
	for(int i = 0; i < n; i++){
		if(ar[i].x == -1) continue;
		printf("%d", ar[i].x);
	}
}
