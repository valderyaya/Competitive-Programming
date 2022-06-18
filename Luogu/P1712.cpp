//#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#include<bits/stdc++.h>
//#include<bits/extc++.h>
//using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
#define F first
#define S second
#define pb push_back
#define em emplace_back
#define REP(i,n) for(register int i=0;i<(n);++i)
#define REP1(i,a,b) for(register int i=(a);i<=(b);++i)
#define ALL(x) (x).begin(),(x).end()
#define pii pair<int,int>
#define pll pair<ll,ll>
#define Rosario ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//#define lb(x) (x&-x)

const int z=2e6+5;
struct qwq{
    int l,r,len;
    bool operator<(const qwq &x)const{return len<x.len;}
}a[1000005];
int n,m,c[z],id,seg[z<<2],laz[z<<2],ans=1e9;
#define ls rt<<1
#define rs ls|1
void down(int rt){
    if(!laz[rt]) return;
    laz[ls]+=laz[rt],laz[rs]+=laz[rt];
    seg[ls]+=laz[rt],seg[rs]+=laz[rt];
    laz[rt]=0;
}
void mdf(int l,int r,int ql,int qr,int rt,int v){
    if(ql<=l&&r<=qr) return laz[rt]+=v,seg[rt]+=v,void();
    down(rt); int mid=l+r>>1;
    if(ql<=mid) mdf(l,mid,ql,qr,ls,v);
    if(qr>mid) mdf(mid+1,r,ql,qr,rs,v);
    seg[rt]=max(seg[ls],seg[rs]);
}
int qry(int l,int r,int ql,int qr,int rt){
    if(ql<=l&&r<=qr) return seg[rt];
    down(rt); int mid=l+r>>1,res=0;
    if(ql<=mid) res=qry(l,mid,ql,qr,ls);
    if(qr>mid) res=max(res,qry(mid+1,r,ql,qr,rs));
    return res;
}
int main(){Rosario
    cin>>n>>m;
    REP1(i,1,n){
        cin>>a[i].l>>a[i].r;
        c[++id]=a[i].l,c[++id]=a[i].r;
        a[i].len=a[i].r-a[i].l;
    }
    sort(a+1,a+1+n);
    sort(c+1,c+1+id); id=unique(c+1,c+1+id)-c-1;
    REP1(i,1,n) a[i].l=lower_bound(c+1,c+1+id,a[i].l)-c,a[i].r=lower_bound(c+1,c+1+id,a[i].r)-c;
    for(int i=1,lst=1;i<=n;++i){
        mdf(1,id,a[i].l,a[i].r,1,1);
        while(seg[1]>=m){
            mdf(1,id,a[lst].l,a[lst].r,1,-1);
            ans=min(ans,a[i].len-a[lst++].len);
        }
    }
    cout<<(ans==1e9?-1:ans)<<"\n";
    return 0;
}
