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

const int z=5e4+5;
struct seg{int lmx,rmx,sum,len;}a[z<<2];
int laz[z<<2],n,m;
void up(int rt){
    int ls=rt<<1,rs=ls|1;
    if(a[ls].sum==a[ls].len) a[rt].lmx=a[ls].len+a[rs].lmx;
    else a[rt].lmx=a[ls].lmx;
    if(a[rs].sum==a[rs].len) a[rt].rmx=a[rs].len+a[ls].rmx;
    else a[rt].rmx=a[rs].rmx;
    a[rt].sum=max({a[ls].sum,a[rs].sum,a[ls].rmx+a[rs].lmx});
}
void down(int rt){
    if(!laz[rt]) return ;
    if(laz[rt]==1){
        laz[rt<<1]=laz[rt<<1|1]=1;
        a[rt<<1].lmx=a[rt<<1].rmx=a[rt<<1].sum=0;
        a[rt<<1|1].lmx=a[rt<<1|1].rmx=a[rt<<1|1].sum=0;
    }else{
        laz[rt<<1]=laz[rt<<1|1]=2;
        a[rt<<1].lmx=a[rt<<1].rmx=a[rt<<1].sum=a[rt<<1].len;
        a[rt<<1|1].lmx=a[rt<<1|1].rmx=a[rt<<1|1].sum=a[rt<<1|1].len;
    }
    laz[rt]=0;
}
void build(int l,int r,int rt){
    a[rt].len=a[rt].lmx=a[rt].rmx=a[rt].sum=r-l+1;
    if(l==r) return ;
    int mid=l+r>>1;
    build(l,mid,rt<<1), build(mid+1,r,rt<<1|1);
}
void modify(int l,int r,int ql,int qr,int rt,int tag){
    if(ql<=l&&r<=qr) return laz[rt]=tag,a[rt].lmx=a[rt].rmx=a[rt].sum=(tag==1?0:a[rt].len),void();
    down(rt); int mid=l+r>>1;
    if(ql<=mid) modify(l,mid,ql,qr,rt<<1,tag);
    if(qr>mid) modify(mid+1,r,ql,qr,rt<<1|1,tag);
    up(rt);
}
int query(int l,int r,int rt,int c){
    if(l==r) return l;
    down(rt); int mid=l+r>>1;
    if(a[rt<<1].sum>=c) return query(l,mid,rt<<1,c);
    else if(a[rt<<1].rmx+a[rt<<1|1].lmx>=c) return mid-a[rt<<1].rmx+1;
    else return query(mid+1,r,rt<<1|1,c);
}
int main(){Rosario
    cin>>n>>m;
    build(1,n,1);
    int x,y,z;
    while(m--){
        cin>>z>>x;
        if(z==1){
            if(a[1].sum>=x){
                y=query(1,n,1,x);
                modify(1,n,y,y+x-1,1,1);
                cout<<y<<"\n";
            }else cout<<"0\n";
        }else cin>>y,modify(1,n,x,x+y-1,1,2);
    }
    return 0;
}
