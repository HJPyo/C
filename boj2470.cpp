#include<stdio.h>
#include<algorithm>
#include<math.h>
#define INF 2147000000
#define min(x,y) (x < y ? x : y)
/*
void merge_sort(int L, int R, int M, int ar[])
{
	int tmp[100001] = {};
	int p0 = L, p1 = L, p2 = M+1;
	
	while(p1 <= M || p2 <= R){
		if(p1 > M)
			tmp[p0++] = ar[p2++];
		else if(p2 > R)
			tmp[p0++] = ar[p1++];
		else if(ar[p1] < ar[p2])
			tmp[p0++] = ar[p1++];
		else
			tmp[p0++] = ar[p2++];
	}
	
	for(int i = L; i <= R; i++){
		ar[i] = tmp[i];
	}
	
	return;
}

void merge(int L, int R, int ar[])
{
	if(L < R){
		int M = (L+R) >> 1;
		merge(L,M,ar);
		merge(M+1,R,ar);
		merge_sort(L,R,M,ar);
	}
	
	return;
}
*/
int main()
{
	int n, ar[111111] = {};
	
	scanf("%d", &n);
	
	for(int i = 0; i < n; i++){
		scanf("%d", &ar[i]);
	}
	
	std::sort(ar,ar+n);
	/*
	for(int i = 0; i < n; i++){
		printf("%d ", ar[i]);
	}
	puts("");
	*/
	int L = 0, R = n-1, minimum = INF;
	int l1, l2;
	
	while(L < R){
		int now = ar[L] + ar[R];
		
		if(abs(now) < minimum){
			minimum = abs(now);
			l1 = L;
			l2 = R;
		}
		
		if(now < 0)
			L++;
		else if(now > 0)
			R--;
		else break;
	}
	
	printf("%d %d", ar[l1], ar[l2]);
}
