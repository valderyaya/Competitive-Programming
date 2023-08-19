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
#define lb(x) x&(-x)
#define pll pair<ll,ll>
#define mkp make_pair
#define ull unsigned long long

inline void rd(ll &ret){
    ret=0;char c=getchar();
    while(c<'0'||c>'9') c=getchar();
    while(c>='0'&&c<='9') ret=(ret<<3)+(ret<<1)+(c^48),c=getchar();
}
const int z=1e4+5;
ll dp[z],n,m,k,p,ans;
signed main(){
    rd(n),rd(m),rd(k);
    for(int i,c,w;i<n;++i) {
        cin>>c>>w;
        for(int j=m;j>=c;--j) dp[j]=max(dp[j],dp[j-c]+w);
    }
    REP1(i,1,k){
        p = m / i;
        ans=0;
        REP1(j,1,p) ans=max(ans, dp[j]);
        cout<<ans*i<<"\n";
    }
    return 0;
}
