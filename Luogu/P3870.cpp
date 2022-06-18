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

int n,m,a[400005],laz[400005];
void down(int rt,int l,int r){
    if(!laz[rt]) return;
    int mid=l+r>>1;
    laz[rt<<1]^=1,laz[rt<<1|1]^=1;
    a[rt<<1]=mid-l+1-a[rt<<1];
    a[rt<<1|1]=r-mid-a[rt<<1|1];
    laz[rt]=0;
}
void mdy(int l,int r,int ql,int qr,int rt){
    if(ql<=l&&r<=qr) return a[rt]=r-l+1-a[rt],laz[rt]^=1,void();
    int mid=l+r>>1; down(rt,l,r);
    if(ql<=mid) mdy(l,mid,ql,qr,rt<<1);
    if(qr>mid) mdy(mid+1,r,ql,qr,rt<<1|1);
    a[rt]=a[rt<<1]+a[rt<<1|1];
}
int query(int l,int r,int ql,int qr,int rt){
    if(ql<=l&&r<=qr) return a[rt];
    int res=0,mid=l+r>>1; down(rt,l,r);
    if(ql<=mid) res=query(l,mid,ql,qr,rt<<1);
    if(qr>mid) res+=query(mid+1,r,ql,qr,rt<<1|1);
    return res;
}
int main(){Rosario
    cin>>n>>m;
    for(int x,y,z;m;m--){
        cin>>x>>y>>z;
        if(x==0) mdy(1,n,y,z,1);
        else cout<<query(1,n,y,z,1)<<"\n";
    }
    return 0;
}
