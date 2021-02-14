// tree[N][0 = parent, 1 = Lnode, 2 = Rnode]
#include<stdio.h>
#include<string.h>

int n;
char tree[101][5];

void preorder(char N)
{
	if(N == '.') return;
	printf("%c", N);
	preorder(tree[N-'A'][1]);
	preorder(tree[N-'A'][2]);
}

void inorder(int N)
{
	if(N == '.') return;
	inorder(tree[N-'A'][1]);
	printf("%c", N);
	inorder(tree[N-'A'][2]);
}

void postorder(int N)
{
	if(N == '.') return;
	postorder(tree[N-'A'][1]);
	postorder(tree[N-'A'][2]);
	printf("%c", N);
}

int main()
{
	memset(tree, -1, sizeof(tree));
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		int a, b, c;
		scanf("%s %s %s", &a, &b, &c);
		tree[a-'A'][1] = b;
		tree[a-'A'][2] = c;
	}
	
	preorder('A'); puts("");
	inorder('A');  puts("");
	postorder('A');puts("");
}
