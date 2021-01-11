#include<iostream>
#define M (S+E)/2
#define INF 1999999999
using namespace std;

int n, m, Bnum, tree[444444];

int Min(int x, int y)
{
	return x < y ? x : y;
}

int f(int S, int E, int Node, int L, int R)
{
	if(E<L || R<S){
		return INF;
	}
	else if(L<=S && E<=R){
		return tree[Node];
	}
	else{
		return Min(f(S,M,Node*2,L,R), f(M+1,E,Node*2+1,L,R));
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;
	
	for(Bnum = 1; Bnum < n; Bnum*=2);
	
	for(int i = 0; i < n; i++){
		cin >> tree[i+Bnum];
	}
	
	for(int i = Bnum-1; i > 0; i--){
		tree[i] = Min(tree[i*2], tree[i*2+1]);
	}
	
	while(m--){
		int L, R;
		cin >> L >> R;
		cout << f(1,Bnum,1,L,R) << '\n';
	}
}
