#include<iostream>
#include<iomanip>
#include<cmath>
#include<set>
#include<float.h>
#define LD long double
using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout << setprecision(11);
	
	int T;
	cin >> T;
	
	while(T--){
		LD a, b, c, d;
		cin >> a >> b >> c >> d;
		
		for(int x = -1000000; x <= 1000000; x++){
			LD now = (a*x*x*x + b*x*x + c*x + d);
			if(fabsf(now - 0.0f) <= FLT_EPSILON){
				cout << now << ' ' << x << '\n';
			}
		}
	}
}
