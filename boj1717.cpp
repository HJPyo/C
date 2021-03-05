#include<stdio.h>

int n, k;
int parent[1000001];

int FindParent(int x)
{
	if(parent[x] == x) return x;
	else return parent[x] = FindParent(parent[x]);
}

int main()
{
	scanf("%d %d", &n, &k);
	for(int i = 0; i <= n; i++){
		parent[i] = i;
	}
	while(k--){
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		if(a == 0){
			b = FindParent(b);
			c = FindParent(c);
			if(b != c) parent[b] = c;
		}
		else{
			printf("%s\n", FindParent(b) == FindParent(c) ? "yes" : "no");
		}
	}
}
