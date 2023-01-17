#include<bits/stdc++.h>
using namespace std;
#define Rosario ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define ll long long
#define F first
#define S second
#define ALL(x) x.begin(),x.end()
#define pii pair<int,int>
#define REP(i,n) for(int i=0;i<n;++i)
#define REP1(i,a,b) for(int i=a;i<=b;++i)
#define em emplace_back
#define lb(x) x&-x
 
#define int ll
const int z=2e5+5;
int n,q,seg[z<<2],laz2[z<<2],laz[z<<2];
#define ls rt<<1
#define rs ls|1
void build(int l,int r,int rt){
    if(l==r) return cin>>seg[rt],void();
    int mid=l+r>>1;
    build(l,mid,ls);build(mid+1,r,rs);
    seg[rt]=seg[ls]+seg[rs];
}
void down(int l,int r,int rt){
    if(!laz[rt]&&!laz2[rt]) return;
    laz2[ls]+=laz2[rt], laz2[rs]+=laz2[rt];
    int mid=l+r>>1;
    laz[ls]+=laz[rt], laz[rs]+=laz[rt]+(mid-l+1)*laz2[rt];
    seg[ls]+=(laz[rt]+laz[rt]+(mid-l)*laz2[rt])*(mid-l+1)/2;
    seg[rs]+=(laz[rt]+(mid-l+1)*laz2[rt]+laz[rt]+(r-l)*laz2[rt])*(r-mid)/2;
    laz[rt]=laz2[rt]=0;
}
void mdf(int l,int r,int ql,int qr,int rt,int v){
    if(ql<=l&&r<=qr){
        seg[rt]+=(v+v+r-l)*(r-l+1)/2;
        laz2[rt]++;
        laz[rt]+=v;
        return;
    }down(l,r,rt);
    int mid=l+r>>1;
    if(ql<=mid) mdf(l,mid,ql,qr,ls,v);
    if(qr>mid) mdf(mid+1,r,ql,qr,rs,v+max(0LL,mid-max(l,ql)+1));
    seg[rt]=seg[ls]+seg[rs];
}
int qry(int l,int r,int ql,int qr,int rt){
    if(ql<=l&&r<=qr) return seg[rt];
    int mid=l+r>>1,res=0;
    down(l,r,rt);
    if(ql<=mid) res=qry(l,mid,ql,qr,ls);
    if(qr>mid) res+=qry(mid+1,r,ql,qr,rs);
    return res;
}
signed main(){ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>q;
    build(1,n,1);
    for(int op,x,y;q--;){
        cin>>op>>x>>y;
        if(op==1) mdf(1,n,x,y,1,1);
        else cout<<qry(1,n,x,y,1)<<"\n";
    }
    return 0;
}
