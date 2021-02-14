#include<stdio.h>
#include<algorithm>
using namespace std;

int n, ar[1001], MH = 0, ans = 0;

int f(int x)
{
	return x<<1|1;
}

int main()
{
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%d", &ar[i]);
		MH = max(MH, ar[i]);
	}
	
	for(int i = 1; i <= MH; i++){
		int len = 0;
		for(int j = 0; j < n+1; j++){
			if(ar[j] >= i) len++;
			else{
				ans = f(len);
				len = 0;
			}
		}
	}
	
	printf("%d", ans);
}
