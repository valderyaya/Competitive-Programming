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
#define wait system("pause");

const int z=2e5+5;
int n,m;
struct seg{int l,r,lmx,rmx,mx,L,R;}a[z<<2];
void up(int rt){
    int ls=rt<<1,rs=ls|1;
    a[rt].l=a[ls].l, a[rt].r=a[rs].r;
    a[rt].mx=max(a[ls].mx,a[rs].mx);
    a[rt].lmx=a[ls].lmx, a[rt].rmx=a[rs].rmx;
    if(a[ls].r!=a[rs].l) {
        a[rt].mx=max(a[rt].mx,a[ls].rmx+a[rs].lmx);
        if(a[rs].mx==a[rs].R-a[rs].L+1) a[rt].rmx=max(a[rt].rmx,a[rs].mx+a[ls].rmx);
        if(a[ls].mx==a[ls].R-a[ls].L+1) a[rt].lmx=max(a[rt].lmx,a[ls].mx+a[rs].lmx);
    }
    a[rt].mx=max({a[rt].mx,a[rt].lmx,a[rt].rmx});
}
void build(int l,int r,int rt){
    a[rt].L=l,a[rt].R=r;
    if(l==r) return a[rt].l=a[rt].r=0,a[rt].lmx=a[rt].rmx=a[rt].mx=1,void();
    int mid=l+r>>1;
    build(l,mid,rt<<1),build(mid+1,r,rt<<1|1);
    up(rt);
}
void modify(int l,int r,int x,int rt){
    if(l==r) return a[rt].l=a[rt].r=(a[rt].l?0:1),void();
    int mid=l+r>>1;
    if(x<=mid) modify(l,mid,x,rt<<1);
    else modify(mid+1,r,x,rt<<1|1);
    up(rt);
}
int main(){Rosario
    cin>>n>>m; int x;
    build(1,n,1);
    while(m--) cin>>x,modify(1,n,x,1),cout<<a[1].mx<<"\n";
//    system("pause");
    return 0;
}
