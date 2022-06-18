#include<bits/stdc++.h>
//#include<bits/extc++.h>
//using namespace __gnu_pbds;
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
#define wait system("pause");


struct qq{ll sum,laz=1,x;}seg[100000<<2];
ll n,m,p;
void build(ll l,ll r,ll rt){
    if(l==r) return cin>>seg[rt].x,void();
    ll mid=l+r>>1;
    build(l,mid,rt<<1),build(mid+1,r,rt<<1|1);
    seg[rt].x=(seg[rt<<1].x+seg[rt<<1|1].x)%p;
}
void down(ll l,ll r,ll rt){
    if(l==r||(seg[rt].sum==0&&seg[rt].laz==1)) return;
    ll ls=rt<<1,rs=ls|1,mid=l+r>>1;
    seg[ls].laz=seg[ls].laz*seg[rt].laz%p;
    seg[ls].sum=(seg[ls].sum*seg[rt].laz+seg[rt].sum)%p;
    seg[ls].x=(seg[ls].x*seg[rt].laz+seg[rt].sum*(mid-l+1))%p;
    seg[rs].laz=seg[rs].laz*seg[rt].laz%p;
    seg[rs].sum=(seg[rs].sum*seg[rt].laz+seg[rt].sum)%p;
    seg[rs].x=(seg[rs].x*seg[rt].laz+seg[rt].sum*(r-mid))%p;
    seg[rt].sum=0,seg[rt].laz=1;
}
void modify1(ll l,ll r,ll ql,ll qr,ll rt,ll v){
    down(l,r,rt);
    if(ql<=l&&r<=qr){
        seg[rt].sum=(seg[rt].sum+v)%p;
        seg[rt].x=(seg[rt].x+v*(r-l+1))%p;
        return;
    }ll mid=l+r>>1;
    if(ql<=mid) modify1(l,mid,ql,qr,rt<<1,v);
    if(qr>mid) modify1(mid+1,r,ql,qr,rt<<1|1,v);
    seg[rt].x=(seg[rt<<1].x+seg[rt<<1|1].x)%p;
}
void modify2(ll l,ll r,ll ql,ll qr,ll rt,ll v){
    down(l,r,rt);
    if(ql<=l&&r<=qr){
        seg[rt].x=seg[rt].x*v%p;
        seg[rt].laz=seg[rt].laz*v%p;
        seg[rt].sum=seg[rt].sum*v%p;
        return;
    }ll mid=l+r>>1;
    if(ql<=mid) modify2(l,mid,ql,qr,rt<<1,v);
    if(qr>mid) modify2(mid+1,r,ql,qr,rt<<1|1,v);
    seg[rt].x=(seg[rt<<1].x+seg[rt<<1|1].x)%p;
}
ll query(ll l,ll r,ll ql,ll qr,ll rt){
    down(l,r,rt);
    if(ql<=l&&r<=qr) return seg[rt].x;
    ll mid=l+r>>1;
    if(qr<=mid) return query(l,mid,ql,qr,rt<<1);
    else if(ql>mid) return query(mid+1,r,ql,qr,rt<<1|1);
    else return (query(l,mid,ql,qr,rt<<1)+query(mid+1,r,ql,qr,rt<<1|1))%p;
}
int main(){//Rosario
    cin>>n>>p;
    build(1,n,1);
    cin>>m;
    int k,a,b,c;
    while(m--){
        cin>>k>>a>>b;
        if(k==1) cin>>c,modify2(1,n,a,b,1,c);
        else if(k==2) cin>>c,modify1(1,n,a,b,1,c);
        else cout<<query(1,n,a,b,1)<<"\n";
    }
//    system("pause");
    return 0;
}
