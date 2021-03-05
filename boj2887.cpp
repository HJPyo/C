#include<iostream>
#include<algorithm>
#include<vector>
#define MAX 100001
using namespace std;
typedef long long int LL;
typedef pair<int,int> P;

struct xyz{ int x, y, z; };
int n, table[MAX];
P X[MAX], Y[MAX], Z[MAX];
LL ans = 0;
vector<xyz>v;

bool cmp(xyz A, xyz B)
{
	return A.z < B.z;
}

bool XX(xyz A, xyz B)
{
	return A.x < B.x;
}

bool YY(xyz A, xyz B)
{
	return A.y < B.y;
}

bool ZZ(xyz A, xyz B)
{
	return A.z < B.z;
}

int Find(int x)
{
	if(table[x] == x) return x;
	else return table[x] = Find(table[x]);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> X[i].first;
		cin >> Y[i].first;
		cin >> Z[i].first;
		X[i].second = i;
		Y[i].second = i;
		Z[i].second = i;
		table[i] = i;
	}
	
	sort(X,X+n);
	sort(Y,Y+n);
	sort(Z,Z+n);
	
	for(int i = 0; i < n-1; i++){
		v.push_back({X[i].second,X[i+1].second,abs(X[i].first-X[i+1].first)});
		v.push_back({Y[i].second,Y[i+1].second,abs(Y[i].first-Y[i+1].first)});
		v.push_back({Z[i].second,Z[i+1].second,abs(Z[i].first-Z[i+1].first)});
	}
	
	sort(v.begin(),v.end(),cmp);
	
	for(int i = 0, cnt = 0; cnt < n-1; i++){
		int A = v[i].x;
		int B = v[i].y;
		int dist = v[i].z;
		
		if(Find(A) == Find(B)) continue;
		else{
			A = Find(A);
			B = Find(B);
			if(A < B) table[B] = A;
			else table[A] = B;
			ans += (LL)dist;
			cnt++;
		}
	}
	
	cout << ans;
}
