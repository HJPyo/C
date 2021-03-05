#include<stdio.h>
#include<vector>
#define MAX 100001
using namespace std;

int n, k;
vector<int>tree[MAX<<2];

void init_()
{
	for(int i = n-1; i > 0; i--){
		int ptr1 = 0;
		int ptr2 = 0;
		int Ltree = tree[i<<1].size();
		int Rtree = tree[i<<1|1].size();
		while(ptr1 < Ltree || ptr2 < Rtree){
			if(ptr1 == Ltree){
				tree[i].push_back(tree[i<<1|1][ptr2++]);
			}
			else if(ptr2 == Rtree){
				tree[i].push_back(tree[i<<1][ptr1++]);
			}
			else if(tree[i<<1][ptr1] < tree[i<<1|1][ptr2]){
				tree[i].push_back(tree[i<<1][ptr1++]);
			}
			else{
				tree[i].push_back(tree[i<<1|1][ptr2++]);
			}
		}
	}
}

int main()
{
	scanf("%d %d", &n, &k);
	
	for(int i = 0, j; i < n; i++){
		scanf("%d", &j);
		tree[i+n].push_back(j);
	}
	
	init_();
	
	while(k--){
		int a, b;
		scanf("%d %d", &a, &b);
		if(a == 1){
			int tmp = tree[n+b-1][0];
			tree[n+b-1].resize(tmp ^ 0);
			init_();
		}
		else{
			printf("%d\n", tree[1][b-1]);
		}
	}
}
