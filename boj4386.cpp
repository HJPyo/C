#include<stdio.h>
#include<math.h>
#include<algorithm>
#include<vector>
using namespace std;
typedef pair<pair<int,int>,double> mypair;

vector<mypair>v;
int n, boss[101];
double X[101], Y[101], ans = 0.0;

bool cmp(mypair a, mypair b)
{
	return a.second < b.second;
}

double dist(double x1, double x2, double y1, double y2)
{
	return sqrt(pow(x1-x2,2) + pow(y1-y2,2));
}

int Find(int x)
{
	if(boss[x] == x) return x;
	else return boss[x] = Find(boss[x]);
}

void Union(int x, int y)
{
	x = Find(x);
	y = Find(y);
	if(x < y) boss[y] = x;
	else boss[x] = y;
}

int main()
{
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		boss[i] = i;
		scanf("%lf %lf", &X[i], &Y[i]);
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(i == j) continue;
			double dis = dist(X[i], X[j], Y[i], Y[j]);
			v.push_back({{i,j},dis});
		}
	}
	sort(v.begin(),v.end(),cmp);
	for(int i = 0, cnt = 0; cnt < n-1; i++){
		int A = v[i].first.first;
		int B = v[i].first.second;
		double dis = v[i].second;
		
		if(Find(A) == Find(B)) continue;
		else{
			Union(A,B);
			ans += dis;
			cnt++;
		}
	}
	printf("%f", ans);
}
