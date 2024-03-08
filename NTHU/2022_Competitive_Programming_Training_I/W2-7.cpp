#pragma GCC optimize("unroll-loops, no-stack-protector, Ofast")
#include<bits/stdc++.h>
using namespace std;
#define StarBurstStream ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define ll long long
#define F first
#define S second
#define ALL(x) x.begin(),x.end()
#define pii pair<int,int>
#define REP(i,n) for(int i=0;i<n;++i)
#define REP1(i,a,b) for(int i=a;i<=b;++i)
#define em emplace_back
#define lb(x) x&-x
#define pll pair<ll,ll>
#define mkp make_pair

int t,m,n,mask,cal;
void dfs(int M,int L,int R, int x, int y,int l, int r){
    if(M > mask) return;
    if(M==mask&&x==n&&y==m) return ++cal,void();
    int legal = mask & ~(M|L|R);
    for(int i = 0; legal; legal ^= i){
        i = lb(legal);
        if(x<n) dfs(M|i, (L|i)<<1, (R|i)>>1, x+1, y, (l|i)<<1, (r|i)>>1);
        else break;
    }
    legal = mask & ~(M|l|r);
    for(int i = 0; legal; legal ^= i){
        i = lb(legal);
        if(y<m) dfs(M|i, (L|i)<<1, (R|i)>>1, x, y+1, l<<1, r>>1);
        else break;
    }
}
signed main(){StarBurstStream
    cin>>t;
    while(t--){
        cin>>n>>m;
        if(n==0&&m==0){cout<<"0\n";continue;}
        mask = (1<<(n+m)) - 1;
        dfs(cal = 0,0,0,0,0,0,0);
        cout<<cal<<"\n";
    }
}
