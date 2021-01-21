#include<stdio.h>
#define I (i+1)

int n, ar[3], Mdp[3][2], mdp[3][2];

int M(int x, int y){ return x > y ? x : y; }
int m(int x, int y){ return x < y ? x : y; }

int main()
{
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		for(int j = 0; j < 3; j++)
			scanf("%d", &ar[j]);
		
		Mdp[0][I%2] = ar[0] + M(Mdp[0][i%2], Mdp[1][i%2]);
		Mdp[1][I%2] = ar[1] + M(Mdp[0][i%2], M(Mdp[1][i%2], Mdp[2][i%2]));
		Mdp[2][I%2] = ar[2] + M(Mdp[1][i%2], Mdp[2][i%2]);
		
		mdp[0][I%2] = ar[0] + m(mdp[0][i%2], mdp[1][i%2]);
		mdp[1][I%2] = ar[1] + m(mdp[0][i%2], m(mdp[1][i%2], mdp[2][i%2]));
		mdp[2][I%2] = ar[2] + m(mdp[1][i%2], mdp[2][i%2]);
	}
	
	printf("%d %d", M(Mdp[0][n%2], M(Mdp[1][n%2], Mdp[2][n%2])), m(mdp[0][n%2], m(mdp[1][n%2], mdp[2][n%2])));
}
