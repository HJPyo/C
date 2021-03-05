#include<stdio.h>
#include<vector>
#define LL long long
using namespace std;

LL int n;
vector<LL int>v1,v2;

int main()
{
	scanf("%lld", &n);
	
	for(int i = 2; n > 1; i++){
		while(n % i == 0){
			n /= i;
			v1.push_back(i);
		}
	}
	
	int v1s = v1.size();
	int v2s;
	
	if(v1s < 4){
		printf("-1");
	}
	else{
		if(v1s % 2 == 0){
			for(int i = 0; i < v1s; i += 2){
				v2.push_back(v1[i] * v1[i+1]);
			}
			v2s = v2.size();
		}
		else{
			for(int i = 0; i < v1s-1; i += 2){
				v2.push_back(v1[i] * v2[i+1]);
			}
			v2s = v2.size();
			v2[v2s-1] *= v1[v1s-1];
		}
		for(int i = 0; i < v2s; i++){
			printf("%lld ", v2[i]);
		}
	}
}
