#include<iostream>
#include<queue>
#define MAX 5000005
using namespace std;

int n, k, ar[MAX];
priority_queue<pair<int,int>>pQ;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> k;
	
	int num, idx;
	
	for(int i = 0; i < n; i++){
		cin >> ar[i];
		pQ.push({-ar[i],i});
		
		num = -pQ.top().first;
		idx = pQ.top().second;
		
		while(idx <= i-k){
			pQ.pop();
			num = -pQ.top().first;
			idx = pQ.top().second;
		}
		
		cout << num << ' ';
	}
}
