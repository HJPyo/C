#include<stdio.h>
#define MAX 1000001
#define LL long long
#define M ((L+R)>>1)

int n, k, Bnum;
LL int tree[MAX<<2];

LL int Sum(int L, int R, int Node, int S, int E)
{
	if(S <= L && R <= E){
		return tree[Node];
	}
	else if(R < S || E < L){
		return 0;
	}
	else{
		return Sum(L,M,Node<<1,S,E) + Sum(M+1,R,Node<<1|1,S,E);
	}
}

LL int Modify(int L, int R, int Node, int T, int Val)
{
	if(T <= L && R <= T){
		return tree[Node] = (LL int)Val;
	}
	else if(R < T || T < L){
		return tree[Node];
	}
	else{
		return tree[Node] = Modify(L,M,Node<<1,T,Val) + Modify(M+1,R,Node<<1|1,T,Val);
	}
}

int main()
{
	scanf("%d %d", &n, &k);
	for(Bnum = 1; Bnum < n; Bnum <<= 1);
	while(k--){
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		if(a == 0){
			printf("%lld\n", Sum(1,Bnum,1,(b < c ? b : c),(b > c ? b : c)));
		}
		else{
			Modify(1,Bnum,1,b,c);
		}
	}
}
