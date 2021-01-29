#include<stdio.h>
#include<algorithm>
using namespace std;

int n, ar[10001];

int main()
{
	int minus = 0, zero = 0, plus = 0, ans = 0;
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%d", &ar[i]);
		if(ar[i] > 0) plus++;
		else if(ar[i] < 0) minus++;
		else zero++;
	}
	int Mv = (minus%2);
	int Zv = (zero%2);
	int Pv = (plus%2);
	
	sort(ar,ar+n);
	for(int i = 0; i < minus - Mv; i+=2){
		ans += ar[i] * ar[i+1];
	}
	if(Mv && !zero) ans += ar[minus-1];
	for(int i = n-1; i >= minus+zero+Pv; i-=2){
		if(ar[i] == 1 || ar[i-1] == 1){
			ans += ar[i] + ar[i-1];
		}
		else ans += ar[i] * ar[i-1];
	}
	if(Pv) ans += ar[minus+zero];
	printf("%d", ans);
}
