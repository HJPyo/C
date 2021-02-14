#include<iostream>
#include<algorithm>
#include<queue>
#define MAX 100001
#define M ((L+R)>>1)
using namespace std;

int n, m, Bnum;
pair<int,int> tree[MAX<<1];

pair<int,int> update(int L, int R, int Node, int T, int Val)
{
	if(T <= L && R <= T){
		return tree[Node] = make_pair(Val,0);
	}
	else if(R < T || T < L){
		return tree[Node];
	}
	else{
		pair<int,int> L_tree = update(L,M,Node<<1,T,Val);
		pair<int,int> R_tree = update(M+1,R,Node<<1|1,T,Val);
		priority_queue<int>pQ;
		pQ.push(L_tree.first); pQ.push(L_tree.second);
		pQ.push(R_tree.first); pQ.push(R_tree.second);
		tree[Node].first = pQ.top(); pQ.pop();
		tree[Node].second = pQ.top();
		while(!pQ.empty()) pQ.pop();
		return tree[Node];
	}
}

pair<int,int> sum(int L, int R, int Node, int S, int E)
{
	if(S <= L && R <= E){
		return tree[Node];
	}
	else if(R < S || E < L){
		return make_pair(0,0);
	}
	else{
		pair<int,int> L_tree = sum(L,M,Node<<1,S,E);
		pair<int,int> R_tree = sum(M+1,R,Node<<1|1,S,E);
		priority_queue<int>pQ;
		pQ.push(L_tree.first); pQ.push(L_tree.second);
		pQ.push(R_tree.first); pQ.push(R_tree.second);
		pair<int,int> Pizza;
		Pizza.first = pQ.top(); pQ.pop();
		Pizza.second = pQ.top();
		while(!pQ.empty()) pQ.pop();
		return Pizza;
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n;
	for(Bnum = 1; Bnum < n; Bnum <<= 1);
	
	for(int i = 0; i < n; i++){
		cin >> tree[i+Bnum].first;
	}
	
	for(int i = Bnum-1; i > 0; i--){
		priority_queue<int>pQ;
		pQ.push(tree[i<<1].first); pQ.push(tree[i<<1].second);
		pQ.push(tree[i<<1|1].first); pQ.push(tree[i<<1|1].second);
		tree[i].first = pQ.top(); pQ.pop();
		tree[i].second = pQ.top();
		while(!pQ.empty()) pQ.pop();
	}
	
	cin >> m;
	
	while(m--){
		int a, b, c;
		cin >> a >> b >> c;
		if(a == 1){
			update(1,Bnum,1,b,c);
		}
		else{
			pair<int,int> Pizza = sum(1,Bnum,1,b,c);
			cout << Pizza.first + Pizza.second << '\n';
		}
	}
}
