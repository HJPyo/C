#include<iostream>
#include<iomanip>
#include<string>
#include<cmath>
#include<set>
#define MOD 1000000007
#define Val 100000000000
#define LL long long
#define LD long double
using namespace std;

LL getnum(string x){
	x = x + '*';
	LL int ret = 0;
	int idx = 0, chk = 11, minus = 0, flag = 0;
	
	if(x[0] == '-'){
		minus = 1;
		idx++;
	}
	
	while(x[idx] != '*' && chk > 0){
		if(x[idx] == '.'){
			flag = 1;
			idx++;
		}
		
		ret = (ret * 10) + (x[idx++] - '0');
		
		if(flag == 1) chk--;
	}
	
	while(chk > 0){
		ret *= 10;
		chk--;
	}
	
	return minus == 1 ? -ret : ret;
}

int main(){
	cout << setprecision(11);
	
	int T;
	cin >> T;
	
	while(T--){
		set<LD>ans;
		string s1, s2, s3, s4;
		cin >> s1 >> s2 >> s3 >> s4;
		
		LL a, b, c, d;
		
		a = getnum(s1);
		b = getnum(s2);
		c = getnum(s3);
		d = getnum(s4);
		
		printf("%lld %lld %lld %lld\n", a, b, c, d);
		
		for(auto it = ans.begin(); it != ans.end(); it++){
			cout << *it << ' ';
		}
		
		cout << '\n';
	}
}
