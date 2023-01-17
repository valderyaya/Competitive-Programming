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
 
const int z=2e5+5;
int seg[z<<2],n,m;
#define ls rt<<1
#define rs rt<<1|1
void build(int l,int r,int rt){
    if(l==r) return cin>>seg[rt],void();
    int mid=l+r>>1;
    build(l,mid,ls);build(mid+1,r,rs);
    seg[rt]=min(seg[ls],seg[rs]);
}
void mdf(int l,int r,int rt,int x,int y){
    if(l==r) return seg[rt]=y,void();
    int mid=l+r>>1;
    if(x<=mid) mdf(l,mid,ls,x,y);
    else mdf(mid+1,r,rs,x,y);
    seg[rt]=min(seg[ls],seg[rs]);
}
int qry(int l,int r,int ql,int qr,int rt){
    if(ql<=l&&r<=qr) return seg[rt];
    int mid=l+r>>1, res=1e9+6;
    if(ql<=mid) res=qry(l,mid,ql,qr,ls);
    if(qr>mid) res=min(res,qry(mid+1,r,ql,qr,rs));
    return res;
}
signed main(){StarBurstStream
    cin>>n>>m;
    build(1,n,1);
    for(int k,x,y;m--;){
        cin>>k>>x>>y;
        if(k==1) mdf(1,n,1,x,y);
        else cout<<qry(1,n,x,y,1)<<"\n";
    }
}
