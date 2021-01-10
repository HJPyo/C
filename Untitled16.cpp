#include <stdio.h>
#define M (L+R)/2
#define _ R-L+1
int n, m, t[555555], l[555555];
void p(int L,int R,int N){
//	printf("DEBUG_PROPAGATE ");
	if(l[N]%2){
		t[N]=_-t[N];
		if(L<R){
			l[N*2]+=l[N];
			l[N*2+1]+=l[N];
		}
	}
	l[N]=0;
}
void update(int L,int R,int N,int S,int E){
//	printf("DEBUG_UPDATE ");
	p(L,R,N);
	if(E<L||R<S)return;
	if(S<=L&&R<=E){
		t[N]=_-t[N];
		if(L<R) {
			l[N*2]++;
			l[N*2+1]++;
		}
		return;
	}
	update(L,M,N*2,S,E);
	update(M+1,R,N*2+1,S,E);
	t[N]=t[N*2]+t[N*2+1];
}
int query(int L,int R,int N,int S,int E){
//	printf("DEBUG_QUERY ");
	p(L,R,N);
	if(E<L||R<S)return 0;
	if(S<=L&&R<=E)return t[N];
	return query(L,M,N*2,S,E)+query(M+1,R,N*2+1,S,E);
}
int main(){
	scanf("%d %d", &n, &m);
	while(m--){
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		if(a == 0) update(1, 1, n, b, c);
		else printf("%d\n", query(1, 1, n, b, c));
		
		for(int i = 1; i < n*2; i++)
		printf("%d|%d ", t[i], l[i]);
		puts("");
	}
}
