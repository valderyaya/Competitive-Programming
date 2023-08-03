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

const int inf=1e9;
int dp[1001][1001],s[1001],n;
signed main(){StarBurstStream
    cin>>n;
    REP1(i,1,n) cin>>s[i],s[i]+=s[i-1];
    REP1(i,0,n) REP1(j,0,n) if(i!=j) dp[i][j]=-inf;
    REP1(i,1,n)
        for(int j=i-1;j>0;--j)
            for(int k=j;k<i;++k)
                dp[j][i]=max(dp[j][i], max(dp[j][k],dp[k+1][i])+(s[k]-s[j-1])*(s[i]-s[k]));
    cout<<dp[1][n]<<"\n";
    return 0;
}
