#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

struct mnopqrstuvw{
	int w, v, u, t, s, r, q, p, o, n, m;
};

int day = -1;
int m, n, o, p, q, r, s, t, u, v, w;
int M, N, O, P, Q, R, S, T, U, V, W;
int Nm,Nn,No,Np,Nq,Nr,Ns,Nt,Nu,Nv,Nw;
int i1,i2,i3,i4,i5,i6,i7,i8,i9,i10,i11;
int Dm[22] = {1,0,0,0,0,0,0,0,0,0,0,-1,0,0,0,0,0,0,0,0,0,0};
int Dn[22] = {0,1,0,0,0,0,0,0,0,0,0,0,-1,0,0,0,0,0,0,0,0,0};
int Do[22] = {0,0,1,0,0,0,0,0,0,0,0,0,0,-1,0,0,0,0,0,0,0,0};
int Dp[22] = {0,0,0,1,0,0,0,0,0,0,0,0,0,0,-1,0,0,0,0,0,0,0};
int Dq[22] = {0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,-1,0,0,0,0,0,0};
int Dr[22] = {0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,-1,0,0,0,0,0};
int Ds[22] = {0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,-1,0,0,0,0};
int Dt[22] = {0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,-1,0,0,0};
int Du[22] = {0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,-1,0,0};
int Dv[22] = {0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,-1,0};
int Dw[22] = {0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,-1};

vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<int>>>>>>>>>>>box;
queue<mnopqrstuvw>Qt;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> m >> n >> o >> p >> q >> r >> s >> t >> u >> v >> w;
	
	box.resize(w,vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<int>>>>>>>>>>(v,vector<vector<vector<vector<vector<vector<vector<vector<vector<int>>>>>>>>>(u,vector<vector<vector<vector<vector<vector<vector<vector<int>>>>>>>>(t,vector<vector<vector<vector<vector<vector<vector<int>>>>>>>(s,vector<vector<vector<vector<vector<vector<int>>>>>>(r,vector<vector<vector<vector<vector<int>>>>>(q,vector<vector<vector<vector<int>>>>(p,vector<vector<vector<int>>>(o,vector<vector<int>>(n,vector<int>(m,0)))))))))));
	
	for(i1 = 0; i1 < w; i1++){
		for(i2 = 0; i2 < v; i2++){
			for(i3 = 0; i3 < u; i3++){
				for(i4 = 0; i4 < t; i4++){
					for(i5 = 0; i5 < s; i5++){
						for(i6 = 0; i6 < r; i6++){
							for(i7 = 0; i7 < q; i7++){
								for(i8 = 0; i8 < p; i8++){
									for(i9 = 0; i9 < o; i9++){
										for(i10 = 0; i10 < n; i10++){
											for(i11 = 0; i11 < m; i11++){
												cin >> box[i1][i2][i3][i4][i5][i6][i7][i8][i9][i10][i11];
												if(box[i1][i2][i3][i4][i5][i6][i7][i8][i9][i10][i11] == 1){
													Qt.push({i1,i2,i3,i4,i5,i6,i7,i8,i9,i10,i11});
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
	
	while(!Qt.empty()){
		M = Qt.front().m;
		N = Qt.front().n;
		O = Qt.front().o;
		P = Qt.front().p;
		Q = Qt.front().q;
		R = Qt.front().r;
		S = Qt.front().s;
		T = Qt.front().t;
		U = Qt.front().u;
		V = Qt.front().v;
		W = Qt.front().w;
		Qt.pop();
		day = max(day,box[W][V][U][T][S][R][Q][P][O][N][M]);
		for(int i = 0; i < 22; i++){
			Nm = M+Dm[i]; if(Nm < 0 || Nm == m) continue;
			Nn = N+Dn[i]; if(Nn < 0 || Nn == n) continue;
			No = O+Do[i]; if(No < 0 || No == o) continue;
			Np = P+Dp[i]; if(Np < 0 || Np == p) continue;
			Nq = Q+Dq[i]; if(Nq < 0 || Nq == q) continue;
			Nr = R+Dr[i]; if(Nr < 0 || Nr == r) continue;
			Ns = S+Ds[i]; if(Ns < 0 || Ns == s) continue;
			Nt = T+Dt[i]; if(Nt < 0 || Nt == t) continue;
			Nu = U+Du[i]; if(Nu < 0 || Nu == u) continue;
			Nv = V+Dv[i]; if(Nv < 0 || Nv == v) continue;
			Nw = W+Dw[i]; if(Nw < 0 || Nw == w) continue;
			if(box[Nw][Nv][Nu][Nt][Ns][Nr][Nq][Np][No][Nn][Nm] == 0){
				box[Nw][Nv][Nu][Nt][Ns][Nr][Nq][Np][No][Nn][Nm] = box[W][V][U][T][S][R][Q][P][O][N][M] + 1;
				Qt.push({Nw,Nv,Nu,Nt,Ns,Nr,Nq,Np,No,Nn,Nm});
			}
		}
	}
	
	day--;
	
	for(i1 = 0; i1 < w; i1++){
		for(i2 = 0; i2 < v; i2++){
			for(i3 = 0; i3 < u; i3++){
				for(i4 = 0; i4 < t; i4++){
					for(i5 = 0; i5 < s; i5++){
						for(i6 = 0; i6 < r; i6++){
							for(i7 = 0; i7 < q; i7++){
								for(i8 = 0; i8 < p; i8++){
									for(i9 = 0; i9 < o; i9++){
										for(i10 = 0; i10 < n; i10++){
											for(i11 = 0; i11 < m; i11++){
												if(box[i1][i2][i3][i4][i5][i6][i7][i8][i9][i10][i11] == 0){
													day = -1;
													goto END;
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
	
	END:
	
	cout << day;
	
	return 0;
}
