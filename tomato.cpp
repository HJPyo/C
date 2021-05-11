#include<stdio.h>
#include<algorithm>
#include<vector>
#include<queue>
#define tomato(i,n) for(i = 0; i < n; i++)
using namespace std;

struct mnopqrstuvw{
	int w, v, u, t, s, r, q, p, o, n, m;
};

int m, n, o, p, q, r, s, t, u, v, w;
int Dm[22] = {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,-1};
int Dn[22] = {0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,-1,0};
int Do[22] = {0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,-1,0,0};
int Dp[22] = {0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,-1,0,0,0};
int Dq[22] = {0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,-1,0,0,0,0};
int Dr[22] = {0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,-1,0,0,0,0,0};
int Ds[22] = {0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,-1,0,0,0,0,0,0};
int Dt[22] = {0,0,0,0,0,0,0,1,0,0,0,0,0,0,-1,0,0,0,0,0,0,0};
int Du[22] = {0,0,0,0,0,0,0,0,1,0,0,0,0,-1,0,0,0,0,0,0,0,0};
int Dv[22] = {0,0,0,0,0,0,0,0,0,1,0,0,-1,0,0,0,0,0,0,0,0,0};
int Dw[22] = {0,0,0,0,0,0,0,0,0,0,1,-1,0,0,0,0,0,0,0,0,0,0};

vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<int>>>>>>>>>>>ar;
queue<mnopqrstuvw>Q;

int i1, i2, i3, i4, i5, i6, i7, i8, i9, i10, i11;

int main(){
	scanf("%d %d %d %d %d %d %d %d %d %d %d", &m, &n, &o, &p, &q, &r, &s, &t, &u, &v, &w);
	
	ar.resize(w,
	vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<int>>>>>>>>>>(v,
	vector<vector<vector<vector<vector<vector<vector<vector<vector<int>>>>>>>>>(u,
	vector<vector<vector<vector<vector<vector<vector<vector<int>>>>>>>>(t,
	vector<vector<vector<vector<vector<vector<vector<int>>>>>>>(s,
	vector<vector<vector<vector<vector<vector<int>>>>>>(r,
	vector<vector<vector<vector<vector<int>>>>>(q,
	vector<vector<vector<vector<int>>>>(p,
	vector<vector<vector<int>>>(o,
	vector<vector<int>>(n,
	vector<int>(m,0)))))))))));
	
	tomato(i1,w){
		tomato(i2,v){
			tomato(i3,u){
				tomato(i4,t){
					tomato(i5,s){
						tomato(i6,r){
							tomato(i7,q){
								tomato(i8,p){
									tomato(i9,o){
										tomato(i10,n){
											tomato(i11,m){
												int tmp;
												scanf("%d", &tmp);
												ar[i1][i2][i3][i4][i5][i6][i7][i8][i9][i10][i11] = tmp;
												if(tmp == 1){
													Q.push({i1,i2,i3,i4,i5,i6,i7,i8,i9,i10,i11});
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	
	int ans = 0;
	
	while(!Q.empty()){
		mnopqrstuvw now = Q.front();
		Q.pop();
		int M = now.m;
		int N = now.n;
		int O = now.o;
		int P = now.p;
		int Q = now.q;
		int R = now.r;
		int S = now.s;
		int T = now.t;
		int U = now.u;
		int V = now.v;
		int W = now.w;
		int i;
		ans = max(ans,ar[w][v][u][t][s][r][q][p][o][n][m]);
		tomato(i,22){
			int nm = M+Dm[i]; if(nm < 0 || nm == m) continue;
			int nn = N+Dn[i]; if(nn < 0 || nn == n) continue;
			int no = O+Dm[i]; if(no < 0 || no == o) continue;
			int np = P+Do[i]; if(np < 0 || np == p) continue;
			int nq = Q+Dp[i]; if(nq < 0 || nq == q) continue;
			int nr = R+Dq[i]; if(nr < 0 || nr == r) continue;
			int ns = S+Dr[i]; if(ns < 0 || ns == s) continue;
			int nt = T+Ds[i]; if(nt < 0 || nt == t) continue;
			int nu = U+Dt[i]; if(nu < 0 || nu == u) continue;
			int nv = V+Du[i]; if(nv < 0 || nv == v) continue;
			int nw = W+Dv[i]; if(nw < 0 || nw == w) continue;
			if(ar[nw][nv][nu][nt][ns][nr][nq][np][no][nn][nm] == 0){
				ar[nw][nv][nu][nt][ns][nr][nq][np][no][nn][nm] = ar[w][v][u][t][s][r][q][p][o][n][m] + 1;
				Q.push({nw,nv,nt,ns,nr,nq,np,no,nn,nm});
			}
		}
	}
	
	printf("%d", ans);
}
