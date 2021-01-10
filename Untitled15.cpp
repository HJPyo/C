#include<stdio.h>
#define _ (R-L+1)
#define I int
#define M (L+R)/2
I n,m,t[518523],l[518523];
void p(int L,int R,int N){
	if(!l[N])return;
	if(L<R){
		l[N*2]+=l[N];
		l[N*2+1]+=l[N];
	}
	t[N]=_-t[N];
	l[N]=0;
}
I u(I L,I R,I N,I S,I E){
	p(L,R,N);
	if(L<=S&&E<=R){
		l[N]=1;
		p(L,R,N);
		return t[N];
	}if(E<L||R<S)return t[N];
	return t[N]=u(L,M,N*2,S,E)+u(M+1,R,N*2+1,S,E);
}
I q(I L,I R,I N,I S,I E){
	p(L,R,N);
	if(L<=S&&E<=R)return t[N];
	if(E<L||R<S)return 0;
	return q(L,M,N*2,S,E)+q(M+1,R,N*2+1,S,E);
}
int main(){
	scanf("%d%d",&n,&m);
	while(m--){
		I a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		if(a){
			printf("%d\n",q(1,n,1,b,c));
		}
		else{
			u(1,n,1,b,c);
		}
	}
}
