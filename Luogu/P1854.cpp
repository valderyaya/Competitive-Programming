//#pragma GCC optimize("unroll-loops, no-stack-protector, Ofast")
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
#define lb(x) x&(-x)
#define pll pair<ll,ll>
#define mkp make_pair
#define ull unsigned long long


int n, m, dp[101][101], a[101][101], id[101];
signed main(){StarBurstStream
    cin >> n >> m;
    REP1(i,1,n) REP1(j,1,m) cin>>a[i][j];
    REP1(i,0,n) REP1(j,0,m) dp[i][j]=-1e9;
    REP1(i,0,m) dp[0][i]=0;
    REP1(i,1,n)
        REP1(j,1,m)
            dp[i][j]=max(dp[i][j-1], dp[i-1][j-1]+a[i][j]);
    cout<<dp[n][m]<<"\n";
    int k=m;
    for(int i=n;i;--i){
        int mx=-1e9, idx;
        REP1(j, 1, k)
            if(mx < dp[i][j]){
                mx=dp[i][j];
                idx=j;
            }
        k=idx-1;
        id[i]=idx;
    }
    REP1(i,1,n) cout<<id[i]<<' ';
}
