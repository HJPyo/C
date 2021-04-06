#include<iostream>
#define LL long long
using namespace std;

int main(){
	int T;
	cin >> T;
	
	while(T--){
		int n, m;
		LL k;
		cin >> n >> m >> k;
		
		int l = 1, r = ((k+2)%n)+1;
		LL tmp = k;
		
		while(tmp > n){
			tmp -= n;
			l++;
		}
		
		cout << l << ' ' << r << '\n';
	}
}
