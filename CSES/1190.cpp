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
int seg[z<<2],n,m,lmx[z<<2],rmx[z<<2],sum[z<<2];
#define ls rt<<1
#define rs rt<<1|1
void up(int rt){
    seg[rt]=max({seg[ls],seg[rs],rmx[ls]+lmx[rs]});
    sum[rt]=sum[ls]+sum[rs];
    lmx[rt]=max(lmx[ls],sum[ls]+lmx[rs]);
    rmx[rt]=max(rmx[rs],sum[rs]+rmx[ls]);
}
void build(int l,int r,int rt){
    if(l==r) return cin>>seg[rt],sum[rt]=seg[rt],lmx[rt]=rmx[rt]=max(0LL,seg[rt]), void();
    int mid=l+r>>1;
    build(l,mid,ls);build(mid+1,r,rs);
    up(rt);
}
void mdf(int l,int r,int rt,int x,int y){
    if(l==r) return seg[rt]=sum[rt]=y,lmx[rt]=rmx[rt]=max(0LL,seg[rt]),void();
    int mid=l+r>>1;
    if(x<=mid) mdf(l,mid,ls,x,y);
    else mdf(mid+1,r,rs,x,y);
    up(rt);
}
 
signed main(){StarBurstStream
    cin>>n>>m;
    build(1,n,1);
    for(int x,y;m--;){
        cin>>x>>y;
        mdf(1,n,1,x,y);
        cout<<seg[1]<<"\n";
    }
}
