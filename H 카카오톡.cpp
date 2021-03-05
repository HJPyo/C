#include<stdio.h>
#include<map>
#include<vector>
#define key1 it->first.first
#define key2 it->first.second
#define val it->second
using namespace std;

int n;
map<pair<int,int>,int>sex;
vector<int>pussy;

int gcd(int x, int y)
{
	return y ? gcd(y,x%y) : x;
}

int main()
{
	scanf("%d", &n);
	
	for(int i = 0; i < n; i++){
		int a, b, c, mod;
		scanf("%d %d %d", &a, &b, &c);
		mod = gcd(a,b);
		a /= mod;
		b /= mod;
		if(sex.find({a,b}) == sex.end()){
			sex[{a,b}] = 1;
		}
		else{
			sex[{a,b}]++;
		}
	}
	
	map<pair<int,int>,int>::iterator it;
	
	for(it = sex.begin(); it != sex.end(); it++){
		pussy.push_back(val);
	}
	
	long long int ans = 0;
	
	for(int i = 0; i < pussy.size(); i++){
		n -= pussy[i];
		ans += (long long int) pussy[i] * n;
	}
	
	printf("%lld", ans);
}
