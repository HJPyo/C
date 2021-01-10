#include<stdio.h>
#include<algorithm>
using namespace std;

int n;
struct info{
	int col, siz;
}ball[200002];

bool Siz_cmp(info a, info b){ return a.siz < b.siz; }
//bool Col_cmp(info a, info b){ return a.col < b.col; }

int f(int Col, int Siz, int *vis)
{
	int Sum;
	for(int i = 0; i < n; i++){
		if(Col == ball[i].col || Siz < ball[i].siz || vis[i]) continue;
		vis[i] = 1;
		Sum += f(Col, Siz+ball[i].siz, vis);
	}
	return Sum;
}

int main()
{
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%d %d", &ball[i].col, &ball[i].siz);
	}
	
//	sort(ball, ball+n, Col_cmp);
	sort(ball, ball+n, Siz_cmp);
	
	for(int i = 0; i < n; i++){
		int vis[200002] = {};
		vis[i] = 1;
		printf("%d\n", f(ball[i].col, ball[i].siz, vis));
	}
}
