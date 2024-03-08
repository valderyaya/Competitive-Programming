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

const ll md=1e9+7;
ll n,f[1000005],rev[1000005];
ll power(ll a,ll b){
    ll ret=1;
    for(;b;b>>=1,a=a*a%md) if(b&1) ret=ret*a%md;
    return ret;
}
signed main(){StarBurstStream
    f[0]=1;
    for(ll i=1;i<=1000000;++i) f[i]=f[i-1]*i%md;
    rev[1000000]=power(f[1000000],md-2);
    for(ll i=1000000-1;i>=0;--i) rev[i]=rev[i+1]*(i+1)%md;
    cin>>n;
    for(ll a,b;n--;) cin>>a>>b,cout<<f[a]*rev[b]%md*rev[a-b]%md<<"\n";
}
