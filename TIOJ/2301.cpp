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



vector<int> v[1000001];
ll n,ans,cnt,mx;
signed main(){StarBurstStream
    cin>>n;
    for(ll i=0,x,y;i<n;++i){
        cin>>x>>y;
        v[x].em(1);
        v[y].em(-1);
        mx=max(mx,y);
    }
    REP1(i,1,mx){
        for(auto &j:v[i]) cnt+=j;
        ans+=cnt*(cnt-1)/2;
    }
    cout<<ans<<"\n";
    return 0;
}
