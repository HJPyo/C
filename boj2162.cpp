#include<stdio.h>
#include<algorithm>
#include<vector>
#define MAX 3003
using namespace std;

int n;
int boss[MAX], vis[MAX];
vector<int>v[MAX];

struct xy{
	int x, y;
};

struct line{
	xy st, en;
}ar[MAX];

int ccw(xy A, xy B, xy C){
	int tmp = (B.x - A.x) * (C.y - A.y) - (B.y - A.y) * (C.x - A.x);
	if(tmp < 0) return -1;
	if(tmp > 0) return 1;
	return 0;
}

int cmp1(xy A, xy B){
	if(A.x == B.x) return A.y < B.y;
	else return A.x < B.x;
}

int cmp2(xy A, xy B){
	if(A.x == B.x) return A.y <= B.y;
	else return A.x <= B.x;
}

int chk(line A, line B){
	int c1 = ccw(A.st, A.en, B.st);
	int c2 = ccw(A.st, A.en, B.en);
	int c3 = ccw(B.st, B.en, A.st);
	int c4 = ccw(B.st, B.en, A.en);
	
	if(c1 * c2 == 0 &&  c3 * c4 == 0){
		if(cmp1(A.en, A.st)) swap(A.st, A.en);
		if(cmp1(B.en, B.st)) swap(B.st, B.en);
		return cmp2(B.st, A.en) && cmp2(A.st, B.en);
	}
	
	return (c1 * c2) <= 0 && (c3 * c4) <= 0;
}

int dfs(int x){
	int tmp = 1;
	vis[x] = 1;
	
	for(int i = 0; i < v[x].size(); i++){
		int next = v[x][i];
		if(!vis[next]){
			tmp += dfs(next);
		}
	}
	
	return tmp;
}

int main(){
	scanf("%d", &n);
	
	for(int i = 0; i < n; i++){
		scanf("%d %d %d %d", &ar[i].st.x, &ar[i].st.y, &ar[i].en.x, &ar[i].en.y);
	}
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < i; j++){
			if(chk(ar[i], ar[j])){
				v[i].push_back(j);
				v[j].push_back(i);
			}
		}
	}
	
	int ans1 = 0, ans2 = 0;
	
	for(int i = 0; i < n; i++){
		if(!vis[i]){
			ans1++;
			ans2 = max(ans2, dfs(i));
		}
	}
	
	printf("%d\n%d\n", ans1, ans2);
	
	return 0;
}
