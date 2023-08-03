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

#define int ll
int n,r,rr,cnt;
pll a[2501];
map<pll,int> mp;
bool dis(pll x,pll y){
    return (x.F-y.F)*(x.F-y.F)+(x.S-y.S)*(x.S-y.S) <= rr;
}
signed main(){StarBurstStream
    cin>>n>>r; rr=r*r;
    for(int x,y,k=0;k<n;++k){
        cin>>x>>y;
        for(int i=x-r;i<=x+r;++i)
            for(int j=y-r;j<=y+r;++j)
                if(dis({i,j},{x,y})) mp[{i,j}]++;
    }
    for(auto &i:mp) if(i.S&1) ++cnt;
    cout<<cnt<<"\n";
    return 0;
}
