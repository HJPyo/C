#include<stdio.h>
#include<vector>
#define MAX 11111
using namespace std;

int n, len[MAX][2], parent[MAX], MAX_deep = -1;
vector< pair<int,int> >inorder;

void sch(int x, int deep)
{
	if(MAX_deep < deep) MAX_deep = deep;
	if(len[x][0] != -1) sch(len[x][0], deep+1);
	inorder.push_back(make_pair(x,deep));
	if(len[x][1] != -1) sch(len[x][1], deep+1);
}

int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		parent[i] = i;
	}
	for(int i = 0; i < n; i++){
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		len[a][0] = b;
		len[a][1] = c;
		parent[b] = a;
		parent[c] = a;
	}
	int Root = 1;
	while(parent[Root] != Root){
		Root = parent[Root];
	}
	sch(Root,0);
	
	vector<int>Begin(MAX_deep+1,MAX);
	vector<int>End(MAX_deep+1,-1);
	for(int i = 0; i < inorder.size(); i++){
		int node = inorder[i].first;
		int level = inorder[i].second;
		if(Begin[level] == MAX) Begin[level] = i;
		End[level] = i;
	}
	
	int ans_level, ans_width = -1;
	for(int i = 0; i < MAX_deep+1; i++){
		if(ans_width < End[i]-Begin[i]){
			ans_width = End[i]-Begin[i];
			ans_level = i;
		}
	}
	
	printf("%d %d", ans_level+1, ans_width+1);
}
