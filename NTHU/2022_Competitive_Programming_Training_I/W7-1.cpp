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

ll power(ll a,ll b,ll md){
    ll ret=1;
    for(;b;b>>=1,a=a*a%md) if(b&1) ret=ret*a%md;
    return ret;
}
const ll p=1e9+7;
signed main(){StarBurstStream
    ll n,a,b,c;
    cin>>n;
    while(n--){
        cin>>a>>b>>c;
        b= power(b,c,p-1);
        cout<<power(a,b,p)<<"\n";
    }
}
