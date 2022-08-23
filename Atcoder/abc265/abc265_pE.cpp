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

const ll md=998244353;
ll n,m,ans,dp[301][301][301],a,b,c,d,e,f;
pll cal(ll i,ll j,ll k){return mkp(a*i+c*j+e*k, b*i+d*j+f*k);}
multiset<pll> s;
signed main(){StarBurstStream
    cin>>n>>m>>a>>b>>c>>d>>e>>f;
    for(ll x,y;m--;) cin>>x>>y, s.insert({x,y});
    dp[0][0][0]=1;
    for(int i=1;i<=n;++i)
        for(int j=0;j<=i;++j)
            for(int k=0;k+j<=i;++k){
                ll l=i-j-k;
                if(s.count(cal(j,k,l))) dp[i][j][k]=0;
                else{
                    if(j>0) (dp[i][j][k]+=dp[i-1][j-1][k])%=md;
                    if(k>0) (dp[i][j][k]+=dp[i-1][j][k-1])%=md;
                    if(j+k<i) (dp[i][j][k]+=dp[i-1][j][k])%=md;
                }
                if(i==n) (ans+=dp[i][j][k])%=md;
            }
    cout<<ans<<"\n";
}
