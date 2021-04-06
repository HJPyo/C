#include<iostream>
#include<cmath>
#include<set>
using namespace std;

int main(){
	int T;
	scanf("%d", &T);
	
	while(T--){
		set<double>ans;
		
		double a, b, c, d;
		scanf("%lf %lf %lf %lf", &a, &b, &c, &d);
		
		for(int i = -1000000; i <= 1000000; i++){
			double x = (double) i;
			double now = (a*x*x*x + b*x*x + c*x + d);
			if(now == 0){
				ans.insert(x);
				b += a * x;
				c += b * x;
				break;
			}
		}
		
		double D = (b*b) - (4.0*a*c);
		
		printf(">>%.9lf\n", D); 
		
		if(D >= 0){
			ans.insert((-b + sqrt(D)) / 2 / a);
		}
		
		if(D > 0){
			ans.insert((-b - sqrt(D)) / 2 / a);
		}
		
		for(auto i = ans.begin(); i != ans.end(); i++){
			printf("%.9lf ", *i);
		}
		
		puts("");
	}
}
