#include<iostream>
#include<algorithm>
#define MAX 300003
#define LL long long
#define cast (LL int)
using namespace std;

int xn, yn, prefix[MAX];
int x[2][MAX], y[2][MAX];
int T1, T2;
LL int ans = 0;

int main()
{
	scanf("%d", &xn);
	for(int i = 0; i < xn; i++){
		int a, b;
		scanf("%d %d", &a, &b);
		x[0][i] = a;
		x[1][i] = b;
	}
	
	scanf("%d", &yn);
	for(int i = 0; i < yn; i++){
		int a, b;
		scanf("%d %d", &a, &b);
		y[0][i] = a;
		y[1][i] = b;
	}
	
	for(int i = 1; i <= yn; i++){
		prefix[i] = prefix[i-1] + y[1][i-1];
	}
	
	scanf("%d %d", &T1, &T2);
	for(int i = 0; i < xn; i++){
		int S = lower_bound(y[0], y[0]+yn, x[0][i]+T1) - y[0];
		int E = upper_bound(y[0], y[0]+yn, x[0][i]+T2) - y[0];
		ans += cast x[1][i] * (prefix[E] - prefix[S]);
	}
	
	printf("%lld", ans);
}
