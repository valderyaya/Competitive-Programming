#include<bits/stdc++.h>
using namespace std;
#define valder ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
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
#define endl "\n"

ll ans,n,m,a[200005],b[11],c[200005];
unordered_map<ll,ll> mp;
signed main(){valder
    cin>>n>>m;
    for(int i=1;i<n;++i) cin>>a[i];
    for(int i=1;i<=m;++i) cin>>b[i];
    for(int i=2;i<=n;++i) c[i]=a[i-1]-c[i-1];
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)
            mp[(b[j]-c[i])*(i&1?1:-1)]++;
    for(auto &i:mp) ans=max(ans,i.S);
    cout<<ans<<endl;
}
