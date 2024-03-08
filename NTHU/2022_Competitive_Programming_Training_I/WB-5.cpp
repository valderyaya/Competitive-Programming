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

vector<pii> v;
int n,m;
signed main(){StarBurstStream
    cin>>n>>m;
    v.resize(n);
    REP1(i,1,n) cin>>v[i-1].F,v[i-1].S=i;
    sort(ALL(v));
    REP(i,n) REP1(j,i+1,n-1){
        ll x=m-v[i].F-v[j].F, l=j+1, r=n-1;
        while(l<r)
            if(v[l].F+v[r].F<x) ++l;
            else if(v[l].F+v[r].F>x) --r;
            else return cout<<v[i].S<<' '<<v[j].S<<' '<<v[l].S<<' '<<v[r].S<<"\n",0;
    }
    cout<<"IMPOSSIBLE\n";
}
