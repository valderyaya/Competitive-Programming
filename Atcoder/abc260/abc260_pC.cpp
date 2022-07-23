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

ll N,X,Y;
ll dfs(ll n,ll col){
    if(n<=1) return col;
    if(col==0) return dfs(n-1,0)+X*dfs(n,1);
    else return dfs(n-1,0)+Y*dfs(n-1,1);
}
signed main(){StarBurstStream
    cin>>N>>X>>Y;
    cout<<dfs(N,0);
}
