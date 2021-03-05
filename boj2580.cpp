#include<iostream>
using namespace std;

pair<int,int> blank[88];
int ar[11][11], cnt = 0;
int visx[11], visy[11], visz[4][4];

void print()
{
	for(int i = 0; i < 9; i++){
		for(int j = 0; j < 9; j++){
			printf("%d ", ar[i][j]);
		}
		puts("");
	}
}

void f(int col)
{
	if(col == cnt){
		print();
		exit(0);
	}
	int x = blank[col].first;
	int y = blank[col].second;
	
	for(int i = 1; i <= 9; i++){
		int now = 1<<i;
		if(visx[x] & now) continue;
		if(visy[y] & now) continue;
		if(visz[x/3][y/3] & now) continue;
		
		visx[x] ^= now;
		visy[y] ^= now;
		visz[x/3][y/3] ^= now;
		ar[x][y] = i;
		
		f(col+1);
		
		visx[x] ^= now;
		visy[y] ^= now;
		visz[x/3][y/3] ^= now;
		ar[x][y] = 0;
	}
}

int main()
{
	for(int i = 0; i < 9; i++){
		for(int j = 0; j < 9; j++){
			scanf("%d", &ar[i][j]);
			if(ar[i][j] == 0){
				blank[cnt].first = i;
				blank[cnt].second = j;
				cnt++;
			}
			else{
				int nowbit = 1<<ar[i][j];
				visx[i] |= nowbit;
				visy[j] |= nowbit;
				visz[i/3][j/3] |= nowbit;
			}
		}
	}
	
	f(0);
}
