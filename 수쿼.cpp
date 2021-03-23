#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int n, k, Bnum;
vector<int>tree1, tree2, lazy;

void propagate(int L, int R, int Node)
{
	if(lazy[Node] == -1) return;
}

int main()
{
	scanf("%d", &n);
	
	for(Bnum = 1; Bnum < n; Bnum <<= 1);
	
	tree1.resize(Bnum<<2,0);
	tree2.resize(Bnum<<2,0);
	lazy.resize(Bnum<<2,-1);
	
	for(int i = 0; i < n; i++){
		scanf("%d", &tree1[i+Bnum]);
		tree2[i+Bnum] = tree1[i+Bnum];
	}
	
	for(int i = Bnum-1; i > 0; i--){
		tree1[i] = max(tree1[i<<1],tree1[i<<1|1]);
		tree2[i] = tree2[i<<1] + tree2[i<<1|1];
	}
	
	scanf("%d", &k);
	
	while(k--){
		int a, b, c, d;
		scanf("%d %d %d", &a, &b, &c);
		
		switch(a){
			case 1{
				scanf("%d", &d);
				break;
			}
			case 2{
				
				break;
			}
			case 3{
				
				break;
			}
		}
	}
}
