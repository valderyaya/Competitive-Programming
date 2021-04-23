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
ll ans;
int laz[z<<2],a[22][z<<2],n,q;
void up(int rt){
    REP(i,22) a[i][rt]=a[i][rt<<1]+a[i][rt<<1|1];
}
void down(int rt,int sum){
    if(!laz[rt]) return;
    laz[ls]^=laz[rt], laz[rs]^=laz[rt];
    REP(i,22)
        if(laz[rt]&(1<<i)){
            a[i][ls]=sum-(sum>>1)-a[i][ls];
            a[i][rs]=(sum>>1)-a[i][rs];
        }
    laz[rt]=0;
}
void build(int l,int r,int rt){
    if(l==r){int x;
        cin>>x;
        REP(i,22) if(x&(1<<i)) a[i][rt]=1;
        return;
    }int mid=l+r>>1;
    build(l,mid,ls),build(mid+1,r,rs);
    up(rt);
}
void modify(int l,int r,int ql,int qr,int rt,int x){
    if(ql<=l&&r<=qr){
        laz[rt]^=x;
        REP(i,22) if(x&(1<<i)) a[i][rt]=r-l+1-a[i][rt];
        return;
    }down(rt,r-l+1); int mid=l+r>>1;
    if(ql<=mid) modify(l,mid,ql,qr,ls,x);
    if(qr>mid) modify(mid+1,r,ql,qr,rs,x);
    up(rt);
}
void que(int l,int r,int ql,int qr,int rt){
    if(ql<=l&&r<=qr){
        REP(i,22) ans+=((ll)a[i][rt]<<i);
        return;
    }down(rt,r-l+1); int mid=l+r>>1;
    if(ql<=mid) que(l,mid,ql,qr,ls);
    if(qr>mid) que(mid+1,r,ql,qr,rs);
}
int main(){Rosario
    cin>>n;
    build(1,n,1);
    cin>>q; int l,r,x,k;
    while(q--){
        cin>>k>>l>>r;
        if(k==1) ans=0,que(1,n,l,r,1),cout<<ans<<"\n";
        else cin>>x,modify(1,n,l,r,1,x);
    }
    return 0;
}
