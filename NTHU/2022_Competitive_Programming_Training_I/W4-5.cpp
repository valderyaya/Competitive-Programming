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


ll n,c;
pll a[200005];
double L=1e9,R=-1e9,cs=0;
const double eps = 1e-11;
double cal(double x){
    double ret=0;
    REP(i,n) ret+=(x-a[i].F)*(x-a[i].F);
    return ret;
}
signed main(){StarBurstStream
    cin>>n>>c;
    REP(i,n) {
        cin>>a[i].F>>a[i].S;
        L=fmin((double)a[i].F,L);
        R=fmax((double)a[i].F,R);
        cs += (c-a[i].S)*(c-a[i].S);
    }
    while(R-L>eps){
        double ml = (L+L+R)/3 ,mr = (R+R+L)/3;
        if(cal(ml) < cal(mr)) R=mr;
        else L=ml;
    }
    cout<<fixed<<setprecision(10)<<cal(L)+cs<<"\n";
}
