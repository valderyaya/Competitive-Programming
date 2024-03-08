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

ll n,k,R,L,a[200001];
bool ck(ll x){
    ll c=1,s=0;
    REP(i,n){
        if(s+a[i]>x) s=0,++c;
        s+=a[i];
    }
    return c<=k;
}
signed main(){StarBurstStream
    cin>>n>>k;
    REP(i,n) cin>>a[i], R+=a[i], L=max(L,a[i]);
    while(L<R){
        ll mid = L+R>>1;
        if(ck(mid)) R=mid;
        else L=mid+1;
    }
    cout<<L<<"\n";
}
