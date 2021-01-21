#include<iostream>
#include<vector>
using namespace std;

int n, k, pay[500001], lazy[500001];
vector<int>tree[500001];

int f(int x, int y)
{
	if(lazy[x]){
		for(int i = 0; i < tree[x].size(); i++)
			lazy[tree[x][i]] += lazy[x];
		pay[x] += lazy[x];
		lazy[x] = 0;
	}
	
	if(x == y) return pay[y];
	
	int sum = 0;
	for(int i = 0; i < tree[x].size(); i++){
		sum += f(tree[x][i], y);
	}
	return sum;
}

int main()
{
	cin >> n >> k;
	
	cin >> pay[1];
	for(int i = 2, a, b; i <= n; i++){
		cin >> a >> b;
		pay[i] = a;
		tree[b].push_back(i);
	}
	
	while(k--){
		char a;
		int b, c;
		cin >> a;
		if(a == 'p'){
			cin >> b >> c;
			lazy[b] += c;
		}
		else{
			cin >> b;
			cout << f(1,b) << '\n';
		}
	}
}
