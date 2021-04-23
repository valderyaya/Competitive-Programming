#include<bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;++i)
#define REP1(i,a,b) for(int i=a;i<=b;++i)
#define loli long long
#define oi ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

const int z=3e5+5;
struct qwq{
    int pos,val,tag,tim;// tag=1 -> query,  tag=0 -> modify
    bool operator<(const qwq &x)const{
        if(pos==x.pos) return tag<x.tag;
        return pos<x.pos;
    }
}a[z<<1];
#define ls rt<<1
#define rs ls|1
int laz[z<<2]={},seg[z<<2]={},n,m,id,ans[z],idx,c[z<<2];
void build(int l,int r,int rt){
    if(l==r) return c[rt]=1,void();
    int mid=l+r>>1;
    build(l,mid,ls);build(mid+1,r,rs);
    c[rt]=c[ls]+c[rs];
}
 void up(int rt){
    if(seg[ls]==seg[rs]) seg[rt]=seg[ls],c[rt]=c[ls]+c[rs];
    else if(seg[ls]>seg[rs]) seg[rt]=seg[rs],c[rt]=c[rs];
    else seg[rt]=seg[ls],c[rt]=c[ls];
 }
void down(int l,int r,int rt){
    if(!laz[rt]) return;
    int mid=l+r>>1;
    seg[ls]+=laz[rt];
    seg[rs]+=laz[rt];
    laz[ls]+=laz[rt],laz[rs]+=laz[rt];
    laz[rt]=0;
 }
void modify(int l,int r,int ql,int qr,int rt,int v){
    if(ql<=l&&r<=qr){
        laz[rt]+=v; seg[rt]+=v;
        return ;
    }down(l,r,rt);int mid=l+r>>1;
    if(ql<=mid) modify(l,mid,ql,qr,ls,v);
    if(qr>mid) modify(mid+1,r,ql,qr,rs,v);
    up(rt);
}
int query(int l,int r,int ql,int qr,int rt){
    if(ql>qr) return 0;
    if(ql<=l&&r<=qr) return seg[rt]==0?c[rt]:0;
    int mid=l+r>>1,s=0;
    down(l,r,rt);
    if(ql<=mid) s=query(l,mid,ql,qr,ls);
    if(qr>mid) s+=query(mid+1,r,ql,qr,rs);
    return s;
}
/*
int que(int l,int r,int ql,int qr,int rt){
    if(ql>qr) return 1e9;
    if(ql<=l&&r<=qr) return seg[rt];
    int mid=l+r>>1,mn=1e9;
    down(l,r,rt);
    if(ql<=mid) mn=que(l,mid,ql,qr,ls);
    if(qr>mid) mn=min(mn,que(mid+1,r,ql,qr,rs));
    return mn;
}
*/
void solve(){
    build(1,m,1);
    REP1(i,1,id){
        //cout<<a[i].pos<<' '<<a[i].val<<' '<<a[i].tag<<' '<<a[i].tim<<endl;
        if(a[i].tag){
            //cout<<que(1,m,1,a[i].tim-1,1)<<' '<<query(1,m,1,a[i].tim-1,1)<<endl;
            //if(que(1,m,1,a[i].tim-1,1)==0)
                ans[a[i].val]=query(1,m,1,a[i].tim-1,1);
        }else modify(1,m,a[i].tim,m,1,a[i].val);
    }
    REP1(i,1,idx) cout<<ans[i]<<"\n";
}
int main(){oi
    cin>>n>>m;
    for(int op,l,r,v,i=1;i<=m;++i){
        cin>>op;
        if(op==1){
            cin>>l>>r>>v;
            a[++id]=qwq{l,v,0,i};
            a[++id]=qwq{r+1,-v,0,i};
        }else{
            cin>>v;
            a[++id]=qwq{v,++idx,1,i};
        }
    }
    sort(a+1,a+1+id);
    solve();
    return 0;
}
