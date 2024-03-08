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

ll n,ans;
pll a[200005];
signed main(){StarBurstStream
    cin>>n;
    REP(i,n) cin>>a[i].F>>a[i].S;
    sort(a,a+n);
    for(ll now=0,i=0;i<n;++i) now+=a[i].F, ans+=a[i].S-now;
    cout<<ans<<"\n";
}
