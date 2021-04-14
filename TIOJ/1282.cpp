//#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
#define REP(i,n) for (int i=0;i<(n);i++)
#define REP1(i,a,b) for(int i=(a);i<=(b);i++)
#define em emplace_back
#define ALL(x) (x).begin(),(x).end()
#define F first
#define S second
#define mkp make_pair
#define pii pair<int,int>
#define Rosario ios::sync_with_stdio(0),cin.tie(0);
#define pll pair<ll,ll> 
#define lb(x) (x&-x)


ll a[100000<<2],b[100005]={},c[100005],d[100005],n,m;
void build(ll l,ll r,ll rt){
    if(l==r){a[rt]=c[l];return;}
    ll m=l+r>>1;
    build(l,m,rt<<1),build(m+1,r,rt<<1|1);
    a[rt]=__gcd(a[rt<<1],a[rt<<1|1]);
}
void add(ll x,ll v){
    for(;x<=n;x+=lb(x)) d[x]+=v;
}
ll get(ll x){
    ll ret=0;
    for(;x;x-=lb(x)) ret+=d[x];
    return ret;
}
ll query(ll l,ll r,ll ql,ll qr,ll rt){
    if(ql<=l&&r<=qr){return a[rt];}
    ll m=l+r>>1,ret=0;
    if(ql<=m) ret=__gcd(ret,query(l,m,ql,qr,rt<<1));
    if(qr>m) ret=__gcd(ret,query(m+1,r,ql,qr,rt<<1|1));
    return abs(ret);
}
void modify(ll l,ll r,ll rt,ll d,ll x){
    if(l==r&&r==d){a[rt]+=x;return;}
    ll m=l+r>>1;
    if(d<=m) modify(l,m,rt<<1,d,x);
    else modify(m+1,r,rt<<1|1,d,x);
    a[rt]=__gcd(a[rt<<1],a[rt<<1|1]); 
}
int main(){Rosario
    cin>>n>>m;
    ll x,y,z,k;
    REP1(i,1,n) cin>>b[i],c[i]=b[i]-b[i-1];
    build(1,n,1);
    while(m--){
        cin>>k>>x>>y;
        if(k&1){cin>>z;
            modify(1,n,1,x,z);
            if(y<n) modify(1,n,1,y+1,-z);
            add(x,z),add(y+1,-z);
        }else cout<<__gcd(b[x]+get(x),query(1,n,x+1,y,1))<<"\n";
    }
//    system("pause");
    return 0;
}
