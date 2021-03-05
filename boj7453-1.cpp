#include<stdio.h>
#include<algorithm>
#include<vector>
#define LL long long
using namespace std;

int n;
vector<LL int>A,B,C,D,v1,v2;

int main()
{
	scanf("%d", &n);
	
	for(int i = 0; i < n; i++){
		int a, b, c, d;
		scanf("%lld %lld %lld %lld", &a, &b, &c, &d);
		A.push_back(a);
		B.push_back(b);
		C.push_back(c);
		D.push_back(d);
	}
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			v1.push_back(A[i]+B[j]);
			v2.push_back(C[i]+D[j]);
		}
	}
	
	sort(v1.begin(),v1.end());
	sort(v2.begin(),v2.end());
	
	int v_size = v1.size();
	int cnt = 0;
	
	for(int i = 0; i < v_size; i++){
		LL int now = -v1[i];
		cnt += upper_bound(v2.begin(),v2.end(),now) - lower_bound(v2.begin(),v2.end(),now);
	}
	
	printf("%d", cnt);
}
