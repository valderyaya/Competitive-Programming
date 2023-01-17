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
int n,q,seg[2][z<<1];
#define rt(l,r) l+r|l!=r
void build(int l,int r){
    if(l==r){
        int v;cin>>v;
        seg[0][rt(l,r)]=v-l, seg[1][rt(l,r)]=v+l;
        return;
    }
    int mid=l+r>>1;
    build(l,mid); build(mid+1,r);
    for(int id=0;id<=1;++id) seg[id][rt(l,r)]=min(seg[id][rt(l,mid)],seg[id][rt(mid+1,r)]);
}
void upd(int l,int r,int x,int v,int id){
    if(l==r) return seg[id][rt(l,r)]=v,void();
    int mid=l+r>>1;
    if(x<=mid) upd(l,mid,x,v,id);
    else upd(mid+1,r,x,v,id);
    seg[id][rt(l,r)]=min(seg[id][rt(l,mid)],seg[id][rt(mid+1,r)]);
}
int qry(int l,int r,int ql,int qr,int id){
    if(ql<=l&&r<=qr) return seg[id][rt(l,r)];
    int mid=l+r>>1,res=1e18;
    if(ql<=mid) res=qry(l,mid,ql,qr,id);
    if(qr>mid) res=min(res,qry(mid+1,r,ql,qr,id));
    return res;
}
signed main(){ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>q;
    build(1,n);
    for(int op,x,y;q--;){
        cin>>op>>x;
        if(op==1){
            cin>>y;
            upd(1,n,x,y-x,0);
            upd(1,n,x,y+x,1);
        }else{
            cout<<min(qry(1,n,1,x,0)+x,qry(1,n,x+1,n,1)-x)<<"\n";
        }
    }   
    return 0;
}
