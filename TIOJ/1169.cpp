//#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#include<bits/stdc++.h>
//#include<bits/extc++.h>
//using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
#define F first
#define S second
#define REP(i,n) for(register int i=0;i<(n);++i)
#define REP1(i,a,b) for(register int i=(a);i<=(b);++i)
#define em emplace_back
#define ALL(x) (x).begin(),(x).end()
#define mkp make_pair
#define pii pair<int,int>
#define pll pair<ll,ll>
#define Rosario ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//#define lb(x) (x&-x)
//#define line cout<<"-------------------------\n";

const int z=1<<24,Z=2e5+5;
struct qq{
    int l=0,r=0,val,len,ren;
}seg[Z<<5];
int n,m,C,rt[z],cnt=0;
void up(int p,int l,int r){
    if(seg[p].l==0&&seg[p].r==0) return seg[p].len=seg[p].ren=seg[p].val=r-l+1,void();
    int mid=l+r>>1;
    if(seg[p].l&&seg[p].r==0){
        if(seg[seg[p].l].len==mid-l+1) seg[p].len=r-l+1;
        else seg[p].len=seg[seg[p].l].len;
        seg[p].val=max(seg[seg[p].l].ren+r-mid,seg[seg[p].l].val);
        seg[p].ren=seg[seg[p].l].ren+r-mid;
    }else if(seg[p].r&&seg[p].l==0){
        if(seg[seg[p].r].ren==r-mid) seg[p].ren=r-l+1;
        else seg[p].ren=seg[seg[p].r].ren;
        seg[p].val=max(seg[seg[p].r].len+mid-l+1,seg[seg[p].r].val);
        seg[p].len=mid-l+1+seg[seg[p].r].len;
    }else{
        seg[p].val=max({seg[seg[p].l].val,seg[seg[p].r].val,seg[seg[p].r].len+seg[seg[p].l].ren});
        if(seg[seg[p].l].len==mid-l+1) seg[p].len=mid-l+1+seg[seg[p].r].len;
        else seg[p].len=seg[seg[p].l].len;
        if(seg[seg[p].r].ren==r-mid) seg[p].ren=r-mid+seg[seg[p].l].ren;
        else seg[p].ren=seg[seg[p].r].ren;
    }
}
void modify(int l,int r,int x,int &p,int v){
    if(!p) p=++cnt,seg[p].ren=seg[p].len=seg[p].val=r-l+1;
    if(l==r) return seg[p].ren=seg[p].len=seg[p].val=v,void();
    int mid=l+r>>1;
    if(x<=mid) modify(l,mid,x,seg[p].l,v);
    else modify(mid+1,r,x,seg[p].r,v);
    up(p,l,r);
}
qq query(int l,int r,int ql,int qr,int p){
    if(ql<=l&&r<=qr) {
        if(p) return seg[p];
        return qq{0,0,r-l+1,r-l+1,r-l+1};
    }
    int mid=l+r>>1;
    if(qr<=mid) return query(l,mid,ql,qr,seg[p].l);
    if(ql>mid) return query(mid+1,r,ql,qr,seg[p].r);
    qq res,L=query(l,mid,ql,qr,seg[p].l),R=query(mid+1,r,ql,qr,seg[p].r);
    res.val=max({L.val,R.val,L.ren+R.len});
    if(L.len==mid-l+1) res.len=L.len+R.len;
    else res.len=L.len;
    if(R.ren==r-mid) res.ren=R.ren+L.ren;
    else res.ren=R.ren;
    return res;
}
int a[Z];
int main(){Rosario
    cin>>n>>m>>C;
    int opt,x,y,k;
    REP(i,n) cin>>a[i],modify(0,n-1,i,rt[a[i]],0);
    while(m--){
        cin>>opt>>x>>y;
        if(opt==1) cin>>k,cout<<query(0,n-1,x,y-1,rt[k]).val<<"\n";
        else modify(0,n-1,x,rt[a[x]],1),a[x]=y,modify(0,n-1,x,rt[a[x]],0);
    }
    return 0;
}
