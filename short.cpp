#import<cstdio>

int n,k,a,b,c[101][101],v[101],_;

void f(int x){
	v[x]=1;
	int i=n+1;
	while(i--)
		if(c[x][i]&&!v[i]){
			_++;
			f(i);
		}
}

main(){
	scanf("%d%d",&n,&k);
	while(k--){
		scanf("%d%d",&a,&b);
		c[a][b]=c[b][a]=1;
	}
	f(1);
	printf("%d",_);
}
