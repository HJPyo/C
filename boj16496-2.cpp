#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int n, flag = -1;
struct st{
	int num;
	string str;
}ar[505];

bool cmp(st x, st y){
	return x.num - y.num > y.num - x.num;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	
	for(int i = 0; i < n; i++){
		cin >> ar[i].str;
		for(int j = 0; j < ar[i].str.length(); j++){
			ar[i].num *= 10;
			ar[i].num += ar[i].str[j] - '0';
			flag = max(flag,ar[i].str[j] - '0');
		}
	}
	
	if(flag == 0){
		cout << '0';
		return 0;
	}
	
	sort(ar,ar+n,cmp);
	
	for(int i = 0; i < n; i++){
		cout << ar[i].str;
	}
	
	return 0;
}
