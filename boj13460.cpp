#include<iostream>
#include<vector>
#include<string>
#include<queue>
using namespace std;

struct board{
	int rx, ry, bx, by, cnt;
	vector<string>ar;
};

int n, k;
int fx, fy;
vector<string>v;
queue<board>q;

int f(){
	int dx[4] = {1,-1,0,0};
	int dy[4] = {0,0,1,-1};
	
	while(!q.empty()){
		int rx = q.front().rx;
		int ry = q.front().ry;
		int bx = q.front().bx;
		int by = q.front().by;
		int cnt = q.front().cnt;
		vector<string>ar = q.front().ar;
		q.pop();
		
		for(int i = 0; i < 4; i++){
			int nrx = rx + dx[i], nry = ry + dy[i];
			int nbx = bx + dx[i], nby = by + dy[i];
			int crx = rx, cry = ry;
			int cbx = bx, cby = by;
			
			
			if(ar[nrx][nry] != '#' || ar[nbx][nby] != '#'){
				int rf = 0, bf = 0;
				vector<string>tmpar = ar;
				
				do{
					if(rf != 2){
						rf = 0;
					}
					if(bf != 2){
						bf = 0;
					}
					
					if(ar[nrx][nry] == 'O' && rf != 2){
						tmpar[crx][cry] = '.';
						rf = 2;
					}
					if(ar[nrx][nry] == '.' && rf != 2){
						tmpar[nrx][nry] = 'R';
						tmpar[crx][cry] = '.';
						rf = 1;
					}
					if(ar[nbx][nby] == 'O' && bf != 2){
						tmpar[cbx][cby] = '.';
						bf = 2;
					}
					if(ar[nbx][nby] == '.' && bf != 2){
						tmpar[nbx][nby] = 'B';
						tmpar[cbx][cby] = '.';
						bf = 1;
					}
					crx = nrx; cry = nry;
					cbx = nbx; cby = nby;
					nrx += dx[i]; nry += dy[i];
					nbx += dx[i]; nby += dy[i];
				}while(rf != 0 || bf != 0);
				
				if(bf == 2){
					continue;
				}
				if(rf == 2){
					return cnt;
				}
				
				q.push({crx, cry, cbx, cby, cnt+1, tmpar});
			}
		}
	}
	
	return -1;
}

int main(){
	cin >> n >> k;
	
	int rx, ry, bx, by;
	
	for(int i = 0; i < n; i++){
		string tmp;
		cin >> tmp;
		v.push_back(tmp);
		
		for(int j = 0; j < k; j++){
			if(tmp[j] == 'R'){
				rx = i;
				ry = j;
			}
			if(tmp[j] == 'B'){
				bx = i;
				by = j;
			}
			if(tmp[j] == 'O'){
				fx = i;
				fy = j;
			}
		}
	}
	
	q.push({rx, ry, bx, by, 0, v});
	
	printf("%d", f());
	
	return 0;
}
