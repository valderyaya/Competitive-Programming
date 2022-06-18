//#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#include<bits/stdc++.h>
//#include<bits/extc++.h>
//using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
#define F first
#define S second
#define REP(i,n) for(int i=0;i<(n);++i)
#define REP1(i,a,b) for(int i=(a);i<=(b);++i)
#define em emplace_back
#define ALL(x) (x).begin(),(x).end()
#define mkp make_pair
#define pii pair<int,int>
#define pll pair<ll,ll>
#define Rosario ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//#define lb(x) (x&-x)

#define ls rt<<1
#define rs rt<<1|1
const int z=1e5+5;
struct seg{int l,r,mx,lmx,rmx,cnt,Lmx,Rmx,Mx;}a[z<<2];
int laz[z<<2],rev[z<<2],n,m;
void up(int rt,int l,int r){
    int mid=l+r>>1;
    a[rt].l=a[ls].l, a[rt].r=a[rs].r;
    a[rt].cnt=a[ls].cnt+a[rs].cnt;
    if(a[ls].r==1&&a[ls].mx==mid-l+1) a[rt].lmx=mid-l+1+a[rs].lmx;
    else a[rt].lmx=a[ls].lmx;
    if(a[rs].l==1&&a[rs].mx==r-mid) a[rt].rmx=r-mid+a[ls].rmx;
    else a[rt].rmx=a[rs].rmx;
    if(a[ls].r==0&&a[ls].Mx==mid-l+1) a[rt].Lmx=mid-l+1+a[rs].Lmx;
    else a[rt].Lmx=a[ls].Lmx;
    if(a[rs].l==0&&a[rs].Mx==r-mid) a[rt].Rmx=r-mid+a[ls].Rmx;
    else a[rt].Rmx=a[rs].Rmx;
    a[rt].mx=max(a[ls].mx,a[rs].mx); a[rt].Mx=max(a[ls].Mx,a[rs].Mx);
    if(a[ls].r==1&&a[ls].r==a[rs].l) a[rt].mx=max(a[rt].mx,a[ls].rmx+a[rs].lmx);
    if(a[ls].r==0&&a[ls].r==a[rs].l) a[rt].Mx=max(a[rt].Mx,a[ls].Rmx+a[rs].Lmx);
}
void dd(int rt,int l,int r){
    swap(a[rt].lmx,a[rt].Lmx);
    swap(a[rt].rmx,a[rt].Rmx);
    swap(a[rt].Mx,a[rt].mx);
    a[rt].cnt=r-l+1-a[rt].cnt;
    a[rt].l^=1,a[rt].r^=1; rev[rt]^=1;
    if(~laz[rt]) laz[rt]^=1;
}
void ch(int rt,int v,int l,int r){
    laz[rt]=v;
    if(v) a[rt].cnt=a[rt].lmx=a[rt].rmx=a[rt].mx=r-l+1,a[rt].Mx=a[rt].Lmx=a[rt].Rmx=0,a[rt].r=a[rt].l=1;
    else a[rt].cnt=a[rt].lmx=a[rt].rmx=a[rt].mx=0,a[rt].Rmx=a[rt].Lmx=a[rt].Mx=r-l+1,a[rt].l=a[rt].r=0;
}
void down(int rt,int l,int r){
    int mid=l+r>>1;
    if(rev[rt]){
        dd(ls,l,mid),dd(rs,mid+1,r);
        rev[rt]=0;
    }
    if(laz[rt]!=-1){
        ch(ls,laz[rt],l,mid),ch(rs,laz[rt],mid+1,r);
        laz[rt]=-1;
    }
}
void build(int l,int r,int rt){laz[rt]=-1;
    if(l==r){
        int x; cin>>x; a[rt].l=a[rt].r=x;
        if(x) a[rt].cnt=r-l+1,a[rt].lmx=a[rt].rmx=a[rt].mx=1;
        else a[rt].Rmx=a[rt].Lmx=a[rt].Mx=1;
        return ;
    }int mid=l+r>>1;
    build(l,mid,ls),build(mid+1,r,rs);
    up(rt,l,r);
}
void modify(int l,int r,int ql,int qr,int rt,int v){
    if(ql<=l&&r<=qr){
        if(v==-1) return dd(rt,l,r),void();
        else return ch(rt,v,l,r),void();
    }down(rt,l,r); int mid=l+r>>1;
    if(ql<=mid) modify(l,mid,ql,qr,ls,v);
    if(qr>mid) modify(mid+1,r,ql,qr,rs,v);
    up(rt,l,r);
}
int query(int l,int r,int ql,int qr,int rt){
    if(ql<=l&&r<=qr) return a[rt].cnt;
    down(rt,l,r); int mid=l+r>>1,sum=0;
    if(ql<=mid) sum=query(l,mid,ql,qr,ls);
    if(qr>mid) sum+=query(mid+1,r,ql,qr,rs);
    return sum;
}
seg query2(int l,int r,int ql,int qr,int rt){
    if(ql<=l&&r<=qr) return a[rt];
    down(rt,l,r); int mid=l+r>>1;
    if(qr<=mid) return query2(l,mid,ql,qr,ls);
    else if(ql>mid) return query2(mid+1,r,ql,qr,rs);
    seg L=query2(l,mid,ql,qr,ls),R=query2(mid+1,r,ql,qr,rs),re;
    re.l=L.l, re.r=R.r;re.cnt=L.cnt+R.cnt;
    if(L.r==1&&L.mx==mid-l+1) re.lmx=mid-l+1+R.lmx;
    else re.lmx=L.lmx;
    if(R.l==1&&R.mx==r-mid) re.rmx=r-mid+L.rmx;
    else re.rmx=R.rmx;
    if(L.r==0&&L.Mx==mid-l+1) re.Lmx=mid-l+1+R.Lmx;
    else re.Lmx=L.Lmx;
    if(R.l==0&&R.Mx==r-mid) re.Rmx=r-mid+L.Rmx;
    else re.Rmx=R.Rmx;
    re.mx=max(L.mx,R.mx), re.Mx=max(L.Mx,R.Mx);
    if(L.r==R.l){
        if(L.r) re.mx=max(re.mx,L.rmx+R.lmx);
        else re.Mx=max(re.Mx,L.Rmx+R.Lmx);
    }return re;
}
// void print(int l,int r,int rt){
//     if(l==r )return cout<<a[rt].cnt<<' ',void();
//     down(rt,l,r); int mid=l+r>>1;
//     print(l,mid,ls),print(mid+1,r,rs);
// }
int main(){Rosario
    cin>>n>>m;
    build(1,n,1);
    int x,l,r;
    while(m--){
        cin>>x>>l>>r; ++l,++r;
        if(x==0) modify(1,n,l,r,1,0);
        else if(x==1) modify(1,n,l,r,1,1);
        else if(x==2) modify(1,n,l,r,1,-1);
        else if(x==3) cout<<query(1,n,l,r,1)<<"\n";
        else cout<<query2(1,n,l,r,1).mx<<"\n";
        //print(1,n,1);puts("");
    }
    return 0;
}
