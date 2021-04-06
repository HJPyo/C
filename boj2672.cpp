#include<iostream>
#include<iomanip>
#include<set>
#include<map>
using namespace std;

int n, ans[111][111];
float ar[33][4], sum = 0.0;
set<float> Xcol, Ycol;
map<float,int> Xm, Ym;
map<int,float> mX, mY;

int main(){
	//cout << setprecision(8);
	cin >> n;
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < 4; j++){
			cin >> ar[i][j];
		}
		ar[i][2] += ar[i][0];
		ar[i][3] += ar[i][1];
		Xcol.insert(ar[i][0]);
		Ycol.insert(ar[i][1]);
		Xcol.insert(ar[i][2]);
		Ycol.insert(ar[i][3]);
	}
	
	int cnt = 0;
	
	for(auto i = Xcol.begin(); i != Xcol.end(); i++){
		Xm.insert({*i,cnt});
		mX.insert({cnt,*i});
		cnt++;
	}
	
	cnt = 0;
	
	for(auto i = Ycol.begin(); i != Ycol.end(); i++){
		Ym.insert({*i,cnt});
		mY.insert({cnt,*i});
		cnt++;
	}
	
	for(int i = 0; i < n; i++){
		for(int j = Xm[ar[i][0]]; j < Xm[ar[i][2]]; j++){
			for(int k = Ym[ar[i][1]]; k < Ym[ar[i][3]]; k++){
				ans[j][k]++;
			}
		}
	}
	
	for(int i = 0; i < Xm.size(); i++){
		for(int j = 0; j < Ym.size(); j++){
			if(ans[i][j] > 0){
				sum += (mX[i+1] - mX[i]) * (mY[j+1] - mY[j]);
			}
		}
	}
	
	cout << sum;
}
