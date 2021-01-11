#include<stdio.h>
#include<algorithm>
using namespace std;

int n, cnt = 0;
struct s{
	int st, en;
}h[100001];

bool cmp(s a, s b)
{
	return (a.en == b.en) ? (a.st < b.st) : (a.en < b.en);
}

int main()
{
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%d %d", &h[i].st, &h[i].en);
	}
	
	sort(h,h+n,cmp);
	
	int i = 0, nt = 0;
	while(i<n){
		if(nt <= h[i].st){
			nt = h[i].en;
			cnt++;
		}
		i++;
	}
	
	printf("%d", cnt);
}
