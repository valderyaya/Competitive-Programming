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
 
const int z=2e5+1;
int n,q,lc[z<<5],rc[z<<5],tot,rt[z];
ll sum[z<<5];
void build(int l,int r,int &o){
    if(!o) o=++tot;
    if(l==r) return cin>>sum[o],void();
    int mid=l+r>>1;
    build(l,mid,lc[o]); build(mid+1,r,rc[o]);
    sum[o]=sum[lc[o]]+sum[rc[o]];
}
ll qry(int l,int r,int ql,int qr,int o){
    if(ql<=l&&r<=qr) return sum[o];
    ll mid=l+r>>1,res=0;
    if(ql<=mid) res=qry(l,mid,ql,qr,lc[o]);
    if(qr>mid) res+=qry(mid+1,r,ql,qr,rc[o]);
    return res;
}
int mdf(int l,int r,int x,int o,int v){
    int p=++tot;
    lc[p]=lc[o], rc[p]=rc[o];
    if(l==r) return sum[p]=v,p;
    int mid=l+r>>1;
    if(x<=mid) lc[p]=mdf(l,mid,x,lc[p],v);
    else rc[p]=mdf(mid+1,r,x,rc[p],v);
    sum[p]=sum[lc[p]]+sum[rc[p]];
    return p;
}
signed main(){ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>q;
    build(1,n,rt[1]);
    for(int op,k,x,y,i=1;q--;){
        cin>>op;
        if(op==3) cin>>k,rt[++i]=rt[k];
        else if(op==1){
            cin>>k>>x>>y;
            rt[k]=mdf(1,n,x,rt[k],y);
        }else{
            cin>>k>>x>>y;
            cout<<qry(1,n,x,y,rt[k])<<"\n";
        }
    }
    return 0;
}
