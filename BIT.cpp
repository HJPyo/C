#include<stdio.h>
#define LL long long
#define MAX 1000001

int n, m, o;
LL int ar[MAX], tree[MAX];

void update(int i, LL int val)
{
	while(i <= n){
		tree[i] += val;
		i += (i & -i);
	}
}

LL int prefix(int i)
{
	LL int res = 0;
	while(i > 0){
		res += tree[i];
		i -= (i & -i);
	}
	return res;
}

int main()
{
	scanf("%d %d %d", &n, &m, &o);
	m += o;
	
	for(int i = 1; i <= n; i++){
		scanf("%lld", &ar[i]);
		update(i, ar[i]);
	}
	
	while(m--){
		int a;
		LL int s, e;
		scanf("%d %lld %lld", &a, &s, &e);
		if(a == 1){
			update(s, e - ar[s]);
			ar[s] = e;
		}
		else{
			printf("%lld\n", prefix(e) - prefix(s-1));
		}
	}
}
