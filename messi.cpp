#include<iostream>
#include<vector>
#define MAX 500005
#define MOD 1<32
#define LLD long long int
using namespace std;

int n, k;
vector<LLD> tmp_link[MAX], tmp_vis(MAX,0);
vector<LLD> tree[MAX], Pl(MAX,0), Ml(MAX,0);

void make_link(int x){
	tmp_vis[x] = 1;
	
	for(int i = 0; i < tmp_link[x].size(); i++){
		int next = tmp_link[x][i];
		if(!tmp_vis[next]){
			tree[x].push_back(next);
			make_link(next);
		}
	}
	
	return;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> k;
	
	for(int i = 0; i < n; i++){
		int a, b;
		tmp_link[a].push_back(b);
		tmp_link[b].push_back(a);
	}
	
	make_link(1);
	
	while(k--){
		int Q, X, Y, V;
		cin >> Q;
		
		switch(Q){
			case 1:{
				cin >> X >> V;
				break;
			}
			case 2:{
				cin >> X >> Y >> V;
				break;
			}
			case 3:{
				cin >> X >> V;
				break;
			}
			case 4:{
				cin >> X >> Y >> V;
				break;
			}
			case 5:{
				cin >> X;
				break;
			}
			case 6:{
				cin >> X >> Y;
				break;
			}
		}
	}
}
