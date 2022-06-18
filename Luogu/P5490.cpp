//#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define F first
#define S second
#define REP(i,n) for(int i=0;i<(n);++i)
#define REP1(i,a,b) for(int i=(a);i<=(b);++i)
#define em emplace_back
#define ALL(x) (x).begin(),(x).end()
#define mkp make_pair
#define pii pair<int,int>
#define pll pair<ll,ll>
#define Rosario ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//#define lb(x) (x&-x)

struct qq{
    ll x,y1,y2,k;
    bool operator<(const qq &a)const{
        return x<a.x;
    }
}q[200005];
ll n,x[200005];
pll seg[900005<<2];
void up(ll l,ll r,ll rt){
    if(seg[rt].F) seg[rt].S=x[r+1]-x[l];
    else seg[rt].S=seg[rt<<1].S+seg[rt<<1|1].S;
}
void modify(ll l,ll r,ll ql,ll qr,ll rt,ll x){
    if(ql<=l&&r<=qr) return seg[rt].F+=x,up(l,r,rt),void();
    ll m=l+r>>1;
    if(ql<=m) modify(l,m,ql,qr,rt<<1,x);
    if(qr>m) modify(m+1,r,ql,qr,rt<<1|1,x);
    up(l,r,rt);
}
int main(){Rosario
    cin>>n;
    ll x2,y2,x1,y1;
    REP1(i,1,n){
        cin>>x1>>y1>>x2>>y2;
        q[i]=qq{x1,y1,y2,1};x[i]=y1;
        q[i+n]=qq{x2,y1,y2,-1};x[i+n]=y2;
    }n<<=1;
    sort(x+1,x+1+n);sort(q+1,q+1+n);
    ll cnt=unique(x+1,x+1+n)-x-1,sum=0;
    REP1(i,1,n-1){
        x1=lower_bound(x+1,x+1+cnt,q[i].y1)-x,x2=lower_bound(x+1,x+1+cnt,q[i].y2)-x;
        modify(1,cnt,x1,x2-1,1,q[i].k);
        sum+=(q[i+1].x-q[i].x)*seg[1].S;
    }cout<<sum<<"\n";
//    system("pause");
    return 0;
}
