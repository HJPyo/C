#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int n, sum = 0;
vector<int>v;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	
	for(int i = 0; i < n; i++){
		int a;
		cin >> a;
		v.push_back(a);
		sum += a;
	}
	
	sort(v.begin(),v.end());
	
	for(int piv = 1; piv <= sum; piv++){
		int L = 0, R = 0, now = v[0], flag = 0;
		
		while(L <= R && R < n){
			if(now < piv){
				now += v[++R];
			}
			else if(now > piv){
				now -= v[L++];
			}
			else{
				flag = 1;
				break;
			}
		}
		
		if(!flag){
			printf("%d", piv);
			break;
		}
	}
}
