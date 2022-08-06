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

int mx=0,n;
vector<int> v[55];
void dfs(int x,int d){
    if(x==1) mx=max(mx,d);
    for(auto &i:v[x]) dfs(i,d+1);
}
signed main(){StarBurstStream
    cin>>n;
    for(int x,i=2;i<=n;++i){
        cin>>x;
        v[i].em(x);
    }
    dfs(n,0);
    cout<<mx;
}
