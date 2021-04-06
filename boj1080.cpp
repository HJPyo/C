#include<iostream>
using namespace std;

int n, k, ar[55][55], table[55][55], greedy[55][55];

int _3x3(int x, int y){
	return	table[x-1][y+1]+table[x][y+1]+	table[x+1][y+1]+
			table[x-1][y]+	table[x][y]+	table[x+1][y]+
			table[x-1][y-1]+table[x][y-1]+	table[x+1][y-1];
}

int main(){
	cin >> n >> k;
	
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= k; j++){
			scanf("%1d", &ar[i][j]);
		}
	}
	
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= k; j++){
			scanf("%1d", &table[i][j]);
			table[i][j] ^= ar[i][j];
			greedy[i][j] = _3x3(i,j);
		}
	}
	
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= k; j++){
			cout << greedy[i][j];
		}
		puts("");
	}
}
