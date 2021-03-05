#include<iostream>
using namespace std;

int n, m, k, boss[55], cnt = 0;

int Find(int x)
{
	if(x == boss[x]) return x;
	else return boss[x] = Find(boss[x]);
}

void Union(int x, int y)
{
	int X = Find(x);
	int Y = Find(y);
	if(X == 1 && Y == 0) boss[y] = 1;
	if(X == 0 && Y == 1) boss[x] = 1;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m >> k;
	
	for(int i = 0, j; i < k; i++){
		cin >> j;
		boss[j] = 1;
	}
	
	while(m--){
		int tmp, party[55] = {}, flag = 0, trueman;
		cin >> tmp;
		for(int i = 0; i < tmp; i++){
			cin >> party[i];
			if(boss[party[i]] == 1){
				flag = 1;
				trueman = party[i];
			}
		}
		if(flag == 1){
			for(int i = 0; party[i] != 0; i++){
				if(party[i] == trueman) continue;
				Union(trueman,party[i]);
			}
		}
		else{
			cnt++;
		}
	}
	printf("%d", cnt);
}
