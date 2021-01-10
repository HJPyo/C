#include<iostream>
using namespace std;

int n, m, tree[444444];

void update(int L,int R,int N,int T,int V)
{
	if(L==T && R==T){
		tree[N] = V;
		return;
	}
	if(L<R){
		int M = (L+R)/2;
		update(L,M,N<<1,T,V);
		update(M+1,R,N<<1|1,T,V);
		tree[N] = tree[N<<1] + tree[N<<1|1];
		return;
	}
}

int query(int L,int R,int N,int S,int E)
{
	if(S<=L && R<=E) return tree[N];
	if(E<L || R<S) return 0;
	int M = (L+R)/2;
	return query(L,M,N<<1,S,E) + query(M+1,R,N<<1|1,S,E);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for(int i = 0, j; i < n; i++){
		cin >> j;
		tree[i+n] = !(j%2);
	}
	
	for(int i = n-1; i > 0; i--)
	tree[i] = tree[i<<1] + tree[i<<1|1];
	
	scanf("%d", &m);
	while(m--){
		int a, b, c;
		cin >> a >> b >> c;
		if(a == 1) update(1,n,1,b,!(c%2));
		if(a == 2) cout << query(1,n,1,b,c) << '\n';
		if(a == 3) cout << (c-b+1) - query(1,n,1,b,c) << '\n';
	}
}
