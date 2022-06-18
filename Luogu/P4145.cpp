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

#define int ll
const int z=1e5+5;
int n,m,sum[z<<2],mx[z<<2];
inline int read(){
    int x=0;char c=getchar();
    while(c>'9'||c<'0') c=getchar();
    while(c>='0'&&c<='9') x=(x<<3)+(x<<1)+(c^48),c=getchar();
    return x;
}
void build(int l,int r,int rt){
    if(l==r) return sum[rt]=read(),mx[rt]=sum[rt],void();
    int mid=l+r>>1;
    build(l,mid,rt<<1); build(mid+1,r,rt<<1|1);
    sum[rt]=sum[rt<<1]+sum[rt<<1|1];
    mx[rt]=max(mx[rt<<1],mx[rt<<1|1]);
}
void modify(int l,int r,int ql,int qr,int rt){
    if(l==r) return sum[rt]=sqrt(sum[rt]),mx[rt]=sqrt(mx[rt]),void();
    int mid=l+r>>1;
    if(ql<=mid&&mx[rt<<1]>1) modify(l,mid,ql,qr,rt<<1);
    if(qr>mid&&mx[rt<<1|1]>1) modify(mid+1,r,ql,qr,rt<<1|1);
    sum[rt]=sum[rt<<1]+sum[rt<<1|1];
    mx[rt]=max(mx[rt<<1],mx[rt<<1|1]);
}
int query(int l,int r,int ql,int qr,int rt){
    if(ql<=l&&r<=qr) return sum[rt];
    int mid=l+r>>1,s=0;
    if(ql<=mid) s=query(l,mid,ql,qr,rt<<1);
    if(qr>mid) s+=query(mid+1,r,ql,qr,rt<<1|1);
    return s;
}
 main(){//Rosario
    n=read();
    build(1,n,1);
    m=read();
    int l,r,x;
    while(m--){
        x=read(),l=read(),r=read();
        if(l>r) l^=r^=l^=r;
        if(x) printf("%lld\n",query(1,n,l,r,1));
        else modify(1,n,l,r,1);
    }
//    system("pause");
    return 0;
}
