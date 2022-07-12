#pragma GCC optimize("O2")
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


signed main(){StarBurstStream
    double x,y,d;
    cin>>x>>y>>d;
    double deg=atan2(y,x), r=hypot(x,y);
    deg += d *acos(-1.)/180;
    cout<<fixed<<setprecision(9)<<cos(deg)*r<<' '<<sin(deg)*r;
}
