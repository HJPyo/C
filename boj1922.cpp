#include<stdio.h>
#define MAX 100001

int n, k, boss[1001];
struct com{
	int c1, c2, val;
}ar[MAX], tmp[MAX];

void Merge_Sort(int L, int R, int M)
{
	int Gp = L;
	int Lp = L, Rp = M+1;
	
	while(Lp <= M || Rp <= R){
		if(Lp > M)
			tmp[Gp++] = ar[Rp++];
		else if(Rp > R)
			tmp[Gp++] = ar[Lp++];
		else if(ar[Lp].val < ar[Rp].val)
			tmp[Gp++] = ar[Lp++];
		else
			tmp[Gp++] = ar[Rp++];
	}
	
	for(int i = L; i <= R; i++)
		ar[i] = tmp[i];
	
	return;
}

void Sort(int L, int R)
{
	if(L < R){
		int M = (L+R) >> 1;
		Sort(L,M);
		Sort(M+1,R);
		Merge_Sort(L, R, M);
	}
	
	return;
}

int Find(int x)
{
	if(boss[x] == x) return x;
	else return boss[x] = Find(boss[x]);
}

void Union(int x, int y)
{
	int A = Find(x);
	int B = Find(y);
	
	if(A < B) boss[B] = A;
	else boss[A] = B;
	
	return;
}

int main()
{
	scanf("%d %d", &n, &k);
	
	for(int i = 0; i < 1001; i++){
		boss[i] = i;
	}
	
	for(int i = 0; i < k; i++){
		scanf("%d %d %d", &ar[i].c1, &ar[i].c2, &ar[i].val);
	}
	
	Sort(0, k-1);
	
	int ans = 0;
	
	for(int i = 0, cnt = 0; cnt < n-1; i++){
		int c1 = ar[i].c1;
		int c2 = ar[i].c2;
		int val = ar[i].val;
		
		if(Find(c1) != Find(c2)){
			Union(c1, c2);
			ans += val;
			cnt++;
		}
	}
	
	printf("%d", ans);
	
	return 0;
}
