#include<stdio.h>

int n, in_order[100001], po_order[100001], vis[100001];

void f(int L1, int R1, int L2, int R2)
{
	if(R1 < 1 || R2 < 1) return;
	if(!vis[po_order[R2]])
		printf("%d ", po_order[R2]);
	vis[po_order[R2]] = 1;
	
	if(L1 >= R1 || L2 >= R2) return;
	
	int piv1 = L1;
	int piv2 = L2;
	
	while(in_order[piv1] != po_order[R2]){
		piv1++;
		piv2++;
	}
	
	f(L1, piv1-1, L2, piv2-1);
	f(piv1+1, R1, piv2, R2-1);
}

int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
		scanf("%d", &in_order[i]);
	for(int i = 1; i <= n; i++)
		scanf("%d", &po_order[i]);
	
	f(1,n,1,n);
}
