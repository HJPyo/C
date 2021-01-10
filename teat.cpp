#include<stdio.h>

int ar[11] = {0,1,2,3,4,5,6,7,8,9,10};

int bs(int L, int R, int V)
{
	while(L<=R){
		int M = (L+R)/2;
		if(L==R) return R-V;
		if(ar[M] < V) R = M-1;
		else L = M+1;
	}
}

int main()
{
	printf("%d", bs(1,10,5));
}
