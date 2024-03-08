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

int n,m,a[23];
vector<int> v;
void dfs(int x,int now){
    if(x==m) {
        for(auto &i:v) cout<<a[i]<<' ';
        return cout<<"\n",void();
    }
    for(int i=now;i<n;++i){
        v.em(i);
        dfs(x+1,i+1);
        v.pop_back();
    }
}
signed main(){StarBurstStream
    cin>>n>>m;
    for(int i=0;i<n;++i) cin>>a[i];
    dfs(0,0);
}
