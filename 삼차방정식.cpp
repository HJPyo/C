#include<iostream>
#include<cmath>
#include<set>
#define ERR 0.000000001
#define RD 1000000000
using namespace std;

int main(){
	int T;
	cin >> T;
	
	while(T--){
		double a, b, c, d;
		set<double>s;
		cin >> a >> b >> c >> d;
		
		int st = -abs((int) ceil(d)) - 2;
		int en = abs((int) ceil(d)) + 2;
		
		for(int x = st; x <= en; x++){
			double now = (double) a*x*x + b*x + c + d/x;
			if(now > -ERR && now < ERR){
				b += (double) a * x;
				c += (double) b * x;
				d = 0.0;
				s.insert((double) x);
				break;
			}
		}
		
		double D = (b*b) - (4.0*a*c);
		
		if(D >= 0){
			s.insert((double) round((-b + sqrt(D)) / a / 2 * RD) / RD);
		}
		if(D > 0){
			s.insert((double) round((-b - sqrt(D)) / a / 2 * RD) / RD);
		}
		
		for(auto it = s.begin(); it != s.end(); it++){
			cout << *it << ' ';
		}
		cout << '\n';
	}
}
