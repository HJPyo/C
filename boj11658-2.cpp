#include<stdio.h>
#define M (L+R)/2

int n, k, Bnum;

class segtree{
	public:
		int tree[4099];
		
		void update(int y, int V)
		{
			tree[y] = V;
			for(int i = Bnum-1; i > 0; i++){
				tree[i] = tree[i<<1] + tree[i<<1|1];
			}
			
		}
		
		int query(int L, int R, int Node, int S, int E)
		{
			if(R < S || E < R){
				return 0;
			}
			else if(L <= S && E <= R){
				return tree[Node];
			}
			else{
				return query(L,M,Node<<1,S,E) + query(M+1,R,Node<<1|1,S,E);
			}
		}
};

class segtreetree{
	public:
		segtree tree[4099];
		
		int update(int x, int y, int V)
		{
			tree[x].update(y,V);
			
		}
}seg;

int main()
{
	scanf("%d %d", &n, &k);
	for(Bnum = 1; Bnum < n; Bnum <<= 1);
	
	
}
