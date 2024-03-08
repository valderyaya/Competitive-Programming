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

#define int ll
const int z=2e5+5;
int seg[z<<2],n,m,laz[z<<2];
#define ls rt<<1
#define rs rt<<1|1
void build(int l,int r,int rt){
    if(l==r) return cin>>seg[rt],void();
    int mid=l+r>>1;
    build(l,mid,ls);build(mid+1,r,rs);
    seg[rt]=seg[ls]+seg[rs];
}
void down(int l,int r,int rt){
    if(!laz[rt])  return;
    int mid=l+r>>1;
    seg[ls]+=(mid-l+1)*laz[rt];
    seg[rs]+=(r-mid)*laz[rt];
    laz[ls]+=laz[rt], laz[rs]+=laz[rt];
    laz[rt] =0;
}
void mdf(int l,int r,int rt,int ql,int qr,int x){
    if(ql<=l&&r<=qr){
        laz[rt]+=x;
        seg[rt]+=(r-l+1)*x;
        return;
    }
    down(l,r,rt);
    int mid=l+r>>1;
    if(ql<=mid) mdf(l,mid,ls,ql,qr,x);
    if(qr>mid) mdf(mid+1,r,rs,ql,qr,x);
    seg[rt]=seg[ls]+seg[rs];
}
int qry(int l,int r,int x,int rt){
    if(l==r) return seg[rt];
    down(l,r,rt);
    int mid=l+r>>1;
    if(x<=mid) return qry(l,mid,x,ls);
    else return qry(mid+1,r,x,rs);
}
signed main(){StarBurstStream
    cin>>n>>m;
    build(1,n,1);
    for(int k,x,y,op;m--;){
        cin>>op;
        if(op==1) cin>>x>>y>>k,mdf(1,n,1,x,y,k);
        else cin>>k,cout<<qry(1,n,k,1)<<"\n";
    }
}
