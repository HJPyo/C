#include<iostream>
using namespace std;

int gcd(int x, int y){
	return y ? gcd(y,x%y) : x;
}

int main(){
	int T;
	cin >> T;
	
	while(T--){
		int a, b, c;
		cin >> a >> b >> c;
		
		int cnt = 0;
		for(int i = c; i <= a; i+=c){
			for(int j = c; j <= b; j+=c){
				if(c == gcd(i,j)) cnt++;
			}
		}
		
		cout << cnt << '\n';
	}
}
