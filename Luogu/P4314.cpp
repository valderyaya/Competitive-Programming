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
const int maxn = 1e5+1,inf = 1e18;
int seg[2][maxn<<2],n,q,add[maxn<<2],tag[maxn<<2],mtag[maxn<<2], madd[maxn<<2];
bitset<maxn<<2> cov;
#define ls rt<<1
#define rs ls|1

inline void cmax(int &x,int y){if(x<y) x=y;}

void up(int rt){
    seg[0][rt]=max(seg[0][ls],seg[0][rs]);
    seg[1][rt]=max(seg[1][ls],seg[1][rs]);
}

void add_m(int rt,int k,int mk){
    if(cov[rt]){
        cmax(mtag[rt],tag[rt]+mk);
        tag[rt]+=k;
    }else{
        cmax(madd[rt],add[rt]+mk);
        add[rt]+=k;
    }
    cmax(seg[1][rt],seg[0][rt]+mk);
    seg[0][rt]+=k;
}

void tag_m(int rt,int k,int mk){
    if(cov[rt]) cmax(mtag[rt],mk);
    else{
        cov[rt]=1;
        mtag[rt]=mk;
    }
    cmax(seg[1][rt],mk);
    seg[0][rt]=tag[rt]=k;
}

void down(int rt){
    add_m(ls,add[rt],madd[rt]);
    add_m(rs,add[rt],madd[rt]);
    add[rt]=madd[rt]=0;
    if(cov[rt]){
        tag_m(ls,tag[rt],mtag[rt]);
        tag_m(rs,tag[rt],mtag[rt]);
        cov[rt]=tag[rt]=mtag[rt]=0;
    }
}

void build(int l,int r,int rt){
    tag[rt]=inf;
    if(l==r) return cin>>seg[0][rt],seg[1][rt]=seg[0][rt],void();
    int mid=l+r>>1;
    build(l,mid,ls); build(mid+1,r,rs);
    up(rt);    
}

void mdf(int l,int r,int ql,int qr,int rt,int ty,int val){
    if(ql<=l&&r<=qr){
        if(ty) add_m(rt,val,val);
        else tag_m(rt,val,val);
        return;
    }
    down(rt); int mid=l+r>>1;
    if(ql<=mid) mdf(l,mid,ql,qr,ls,ty,val);
    if(qr>mid) mdf(mid+1,r,ql,qr,rs,ty,val);
    up(rt);
}

int qry(int l,int r,int ql,int qr,int rt,int ty){
    if(ql<=l&&r<=qr) return seg[ty][rt];
    down(rt); int mid=l+r>>1,res=-inf;
    if(ql<=mid) res=qry(l,mid,ql,qr,ls,ty);
    if(qr>mid) cmax(res,qry(mid+1,r,ql,qr,rs,ty));
    return res;
}

signed main(){StarBurstStream
    cin>>n;
    build(1,n,1);
    cin>>q;
    char c;
    for(int x,y,z;q--;){
        cin>>c>>x>>y;
        if(c=='Q') cout<<qry(1,n,x,y,1,0)<<"\n";
        else if(c=='A') cout<<qry(1,n,x,y,1,1)<<"\n";
        else cin>>z, mdf(1,n,x,y,1,c=='P',z);
    }    
}
