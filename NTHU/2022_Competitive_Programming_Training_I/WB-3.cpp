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

int n,m,ans;
vector<pii> v;
multiset<int> s;
signed main(){StarBurstStream
    cin>>n>>m;
    v.resize(n);
    REP(i,n) cin>>v[i].S>>v[i].F;
    REP(i,m) s.insert(-1);
    sort(ALL(v));
    REP(i,n){
        auto it = s.upper_bound(v[i].S);
        if(it == s.begin()) continue;
        ++ans;
        s.erase(prev(it));
        s.insert(v[i].F);
    }cout<<ans<<"\n";
}
