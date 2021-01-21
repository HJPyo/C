#include<bits/stdc++.h>
#define f(i,l,r) for(int i=l;i<r;++i)
using namespace std;
 
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int a[]={25,10},s[100]={0};
    f(i,1,100)s[i]=i;
    f(i,0,2)f(j,a[i],100)s[j]=min(s[j],s[j-a[i]]+1);
    
    int T;cin>>T;
    while(T--){
        long long price;cin>>price;
        int ans=0;
        while(price){
            ans+=s[price%100];
            price/=100;
        }
        cout<<ans<<'\n';
    }
    return 0;
}
 
