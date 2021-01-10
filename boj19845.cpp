#include<iostream>
using namespace std;

int n, m, ar[2555555] = {};

int f(int x, int y)
{
	if(ar[x] < y) return 0;
	int L = 1, R = n, Ans;
	
	while(L <= R){
		int M = (L+R)/2;
		
		if(L >= R){
			Ans = (ar[M] < y) ? L-1 : L;
			break;
		}
		
		if(ar[M] >= y) L = M+1;
		else R = M;
	}
	return Ans-x + ar[x]-y+1;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
		cin >> ar[i];
	
	while(m--){
		int X, Y;
		cin >> X >> Y;
		cout << f(X,Y) << '\n';
	}
}
