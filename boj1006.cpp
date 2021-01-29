#include<stdio.h>
#include<vector>
using namespace std;

int t, n, k;
vector< vector<int> >ar;
vector< vector<int> >dp;

int main()
{
	scanf("%d", &t);
	
	while(t--){
		ar.clear();
		dp.clear();
		ar.resize(2,vector<int>(10001,0));
		dp.resize(2,vector<int>(10001,0));
		
		scanf("%d %d", &n, &k);
		for(int i = 0; i < 2; i++){
			for(int j = 0, k; j < n; j++){
				scanf("%d", &k);
				ar[i][j] = k;
			}
		}
		
		
	}
}
