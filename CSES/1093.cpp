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
#define lb(x) x&-x
#define pll pair<ll,ll>
#define mkp make_pair
 
int n,dp[250501],m;
const int mod=1e9+7;
signed main(){StarBurstStream
    cin>>n; m = (n+1)*n/4;
    if(n%4 && n%4!=3) return cout<<0,0;
    dp[0]=1;
    REP1(i,1,n-1) for(int j=m;j;--j) if(j-i>=0) (dp[j]+=dp[j-i])%=mod;
    cout<<dp[m]<<"\n";
}
