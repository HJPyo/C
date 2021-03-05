#include<iostream>
#include<algorithm>
using namespace std;

bool cmp(int x, int y)
{
	return x > y;
}

int main()
{
	int n, ar[100001], ans = -1;
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> ar[i];
	}
	sort(ar,ar+n,cmp);
	for(int i = 0; i < n; i++){
		ans = max(ans,ar[i]*(i+1));
	}
	cout << ans;
}
