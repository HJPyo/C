#include<stdio.h>
#include<vector>
using namespace std;

int main()
{
	int n;
	scanf("%d", &n);
	
	vector<int>v,prime(n+1,0);
	prime[0] = prime[1] = 1;
	
	for(int i = 2; i < n+1; i++){
		if(prime[i]) continue;
		for(int j = i<<1; j < n+1; j += i){
			prime[j] = 1;
		}
		v.push_back(i);
	}
	
	int v_size = v.size();
	
	for(int i = 0; i < v_size; i++){
		if(v[i] > n) break;
		for(int j = i; j < v_size; j++){
			if(v[i]+v[j] > n) break;
			for(int k = j; k < v_size; k++){
				if(v[i]+v[j]+v[k] > n) break;
				for(int l = k; l < v_size; l++){
					if(v[i]+v[j]+v[k]+v[l] > n) break;
					if(v[i]+v[j]+v[k]+v[l] == n){
						printf("%d %d %d %d", v[i], v[j], v[k], v[l]);
						return 0;
					}
				}
			}
		}
	}
	
	printf("%d", -1);
}
