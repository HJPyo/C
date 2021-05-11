#include<stdio.h>
#define LL long long
#define M (L+R)/2

int n, ar[100001];
LL int ans = 0;

void ms(int L, int R, int mid)
{
	int tmp[100001];
	int cur = L;
	int piv1 = L;
	int piv2 = mid+1;
	LL int sum = 0;
	
	while(cur <= R){
		if(piv1 == mid+1){
			tmp[cur++] = ar[piv2++];
			sum++;
		}
		else if(piv2 == R+1){
			tmp[cur++] = ar[piv1++];
			ans += sum;
		}
		else if(ar[piv1] <= ar[piv2]){
			tmp[cur++] = ar[piv1++];
			ans += sum;
		}
		else{
			tmp[cur++] = ar[piv2++];
			sum++;
		}
	}
	
	for(int i = L; i <= R; i++){
		ar[i] = tmp[i];
	}
}

void merge(int L, int R)
{
	if(L < R){
		merge(L,M);
		merge(M+1,R);
		ms(L,R,M);
	}
}

int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		scanf("%d", &ar[i]);
	}
	merge(1,n);
	printf("%lld", ans);
}
