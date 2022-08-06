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

ll n,L,R,a[200001],sum[200001],mn;
multiset<ll> s;
signed main(){StarBurstStream
    cin>>n>>L>>R;
    for(int i=1;i<=n;++i) cin>>a[i],sum[i]=sum[i-1]+a[i],mn+=a[i];
    
    for(int i=n;i;--i)
        s.insert(sum[i]+(n-i)*R);
    for(int i=1;i<=n;++i){
        mn=min(mn,i*L+*s.begin()-sum[i]);
        auto it=s.find(sum[i]+(n-i)*R);
        s.erase(it);
    }
    s.clear();
    for(int i=1;i<=n;++i)
        s.insert((i-1)*L+sum[n]-sum[i-1]);
    for(int i=n;i;--i) {
        mn=min(mn,*s.begin()+(n-i+1)*R-(sum[n]-sum[i-1]));
        auto it=s.find((i-1)*L+sum[n]-sum[i-1]);
        s.erase(it);
    }
    cout<<mn;
}
