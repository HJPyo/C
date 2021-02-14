#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#define MAX 300003
using namespace std;

int n, k;
long long int sum = 0;
priority_queue<int>pQ;
vector< pair<int,int> >jew;
vector< int >bag;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	cin >> n >> k;
	for(int i = 0, a, b; i < n; i++){
		cin >> a >> b;
		jew.push_back(make_pair(a,b));
	}
	for(int i = 0, a; i < k; i++){
		cin >> a;
		bag.push_back(a);
	}
	
	sort(jew.begin(),jew.end());
	sort(bag.begin(),bag.end());
	
	for(int i = 0, j = 0; i < k; i++){
		while(j < n && jew[j].first <= bag[i]){
			pQ.push(jew[j].second);
			j++;
		}
		if(!pQ.empty()){
			sum += pQ.top();
			pQ.pop();
		}
	}
	
	cout << sum;
}
