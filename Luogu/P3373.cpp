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
#define lb(x) (x&-x)

struct qq{ll x,sum,mul=1;}a[100005<<2];
ll n,m,p;
void build(ll l,ll r,ll rt){
    if(l==r) return cin>>a[rt].x,void();
    ll mid=l+r>>1;
    build(l,mid,rt<<1);build(mid+1,r,rt<<1|1);
    a[rt].x=(a[rt<<1].x+a[rt<<1|1].x)%p;
}
void down(ll l,ll r,ll rt){
    if(a[rt].sum==0&&a[rt].mul==1) return;
    ll mid=l+r>>1;
    a[rt<<1].x=(a[rt<<1].x*a[rt].mul+a[rt].sum*(mid-l+1))%p;
    a[rt<<1].sum=(a[rt<<1].sum*a[rt].mul+a[rt].sum)%p;
    a[rt<<1].mul=a[rt<<1].mul*a[rt].mul%p;
    a[rt<<1|1].x=(a[rt<<1|1].x*a[rt].mul+a[rt].sum*(r-mid))%p;
    a[rt<<1|1].sum=(a[rt<<1|1].sum*a[rt].mul+a[rt].sum)%p;
    a[rt<<1|1].mul=a[rt<<1|1].mul*a[rt].mul%p;
    a[rt].sum=0,a[rt].mul=1;
}
ll query(ll l,ll r,ll ql,ll qr,ll rt){
    if(l!=r) down(l,r,rt);
    if(ql<=l&&r<=qr) return a[rt].x;
    ll mid=l+r>>1;
    if(qr<=mid) return query(l,mid,ql,qr,rt<<1);
    else if(ql>mid) return query(mid+1,r,ql,qr,rt<<1|1);
    else return (query(l,mid,ql,qr,rt<<1)+query(mid+1,r,ql,qr,rt<<1|1))%p;
}
void mod1(ll l,ll r,ll ql,ll qr,ll rt,ll v){
    if(l!=r) down(l,r,rt);
    if(ql<=l&&r<=qr){
        a[rt].x=a[rt].x*v%p;
        a[rt].sum=a[rt].sum*v%p;
        a[rt].mul=a[rt].mul*v%p;
        return;
    }ll mid=l+r>>1;
    if(ql<=mid) mod1(l,mid,ql,qr,rt<<1,v);
    if(qr>mid) mod1(mid+1,r,ql,qr,rt<<1|1,v);
    a[rt].x=(a[rt<<1].x+a[rt<<1|1].x)%p;
}
void mod2(ll l,ll r,ll ql,ll qr,ll rt,ll v){
    if(l!=r) down(l,r,rt);
    if(ql<=l&&r<=qr){
        a[rt].x=(a[rt].x+v*(r-l+1))%p;
        a[rt].sum=(a[rt].sum+v)%p;
        return;
    }ll mid=l+r>>1;
    if(ql<=mid) mod2(l,mid,ql,qr,rt<<1,v);
    if(qr>mid) mod2(mid+1,r,ql,qr,rt<<1|1,v);
    a[rt].x=(a[rt<<1].x+a[rt<<1|1].x)%p;
}
int main(){Rosario
    cin>>n>>m>>p;
    ll k,x,y,z;
    build(1,n,1);
    while(m--){
        cin>>k;
        if(k==1) cin>>x>>y>>z,mod1(1,n,x,y,1,z);
        else if(k==2) cin>>x>>y>>z,mod2(1,n,x,y,1,z);
        else cin>>x>>y,cout<<query(1,n,x,y,1)<<"\n";
    }
//    system("pause");
    return 0;
}
