#include<stdio.h>
#include<math.h>
#include<algorithm>
#define LL long long
#define INF 9999999999
using namespace std;

int n, ar[5005];
LL int ans = INF;

int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; scanf("%d", &ar[i++]));
	sort(ar+1,ar+n+1);
	
	int Liquid[3] = {};
	for(int i = 1; i <= n; i++){
		int L = 1, R = n;
		while(L < R && L <= n && R >= 1){
			if(L == i){ L++; continue; }
			else if(R == i){ R--; continue; }
			
			LL int now = (LL int) ar[i] + ar[L] + ar[R];		
			if(abs(now) < ans){
				ans = abs(now);
				Liquid[0] = ar[i];
				Liquid[1] = ar[L];
				Liquid[2] = ar[R];
			}
			
			if(now <= 0)L++;
			else if(now > 0)R--;
		}
	}
	
	sort(Liquid,Liquid+3);
	
	for(int i = 0; i < 3; i++){
		printf("%d ", Liquid[i]);
	}
}
