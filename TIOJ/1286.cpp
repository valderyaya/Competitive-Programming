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

const ll mod=1e6;
ll power(ll a,ll n){
    ll ret=1;
    for(;n;n>>=1,a=a*a%mod) if(n&1) ret=ret*a%mod;
    return ret;
}
ll a,b,c,d,ans;
signed main(){StarBurstStream
    cin>>a>>b>>c>>d;
    for(;a<=d;a+=b) ans=(ans+power(a,c))%mod;
    cout<<ans;
    return 0;
}
