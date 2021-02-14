#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll seg[4567890] = {0};
ll arr[1234567] = {0};

ll init(int node, int s, int e){
    if(s==e) return seg[node] = arr[s];
    int m = (s+e)/2;
    return seg[node] = init(node*2,s,m) + init(node*2+1,m+1,e);
}

ll query(int node, int s, int e, int l, int r){
    if(e< l || r< s) return 0;
    if(l<=s || e<=r) return seg[node];
    int m = (s+e)/2;
    
    return query(node*2,s,m,l,r)
         + query(node*2+1,m+1,e,l,r); 
}

void update(int node, int s, int e, int idx, ll diff){
    if(idx < s || e < idx) return;
    if(s!=e){
    	int m = (s+e)/2;
        update(node*2, s, m, idx, diff);
        update(node*2+1, m+1, e, idx, diff);
        return;
    }
    seg[node] = arr[idx];
}

int main(){
    int n,m;
    int a,b,c;
    scanf("%d %d", &n, &m);
    init(1,1,n);
    
    for(int i=0; i<m; i++){
        scanf("%d %d %d", &a, &b, &c);
        if(a==0){
            if(b>c) swap(b,c);
            printf("[%lld]\n", query(1,1,n,b,c));
        }
        if(a==1){
            arr[b] = c;
            update(1,1,n,b,c);
        }
    }
}
