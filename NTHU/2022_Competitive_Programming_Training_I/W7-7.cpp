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

bool ck;
ll exgcd(ll a,ll b,ll &x,ll &y){
    if(!b) return x=1,y=0,a;
    ll r=exgcd(b,a%b,x,y),t;
    t=x; x=y; y=t-a/b*y;
    return r;
}
ll sol(ll a,ll b,ll c){
    ll x,y,res,g;
    g=exgcd(a,b,x,y);
    if(c%g){
        cout<<-1<<'\n';
        return ck=1;
    }
    x*=c/g, b/=g;
    if(b<0) b=-b;
    res=x%b;
    return res+(res<=0?b:0);
}
ll a,b,ax,ay,n,m,x,y,xx,yy,fx,fy,t;
signed main(){StarBurstStream
    cin>>t;
    while(t--){ck=0;
    cin>>n>>m>>x>>y>>xx>>yy;
    if(!xx){
        if(!x||x==n) cout<<x<<' '<<(yy>0?m:0)<<'\n';
        else cout<<-1<<'\n';
        continue;
    }
    if(!yy){
        if(!y||y==m) cout<<(xx>0?n:0)<<' '<<y<<'\n';
        else cout<<-1<<'\n';
        continue;
    }
    fx=fy=0;
    if(xx==-1) fx=1,x=n-x;
    if(yy==-1) fy=1,y=m-y;
    a=sol(n,m,x-y);
    if(ck) continue;
    b=-((x-y)-a*n)/m;
    ax=n,ay=m;
    if(a%2==0) ax=n-ax;
    if(b%2==0) ay=m-ay;
    if(fx) ax=n-ax;
    if(fy) ay=m-ay;
    cout<<ax<<' '<<ay<<'\n';
    }
}
