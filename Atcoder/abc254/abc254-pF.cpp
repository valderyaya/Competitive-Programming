#include<bits/stdc++.h>
using namespace std;
#define valder ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define ll long long
#define F first
#define S second
#define ALL(x) x.begin(),x.end()
#define pii pair<int,int>
#define REP(i,n) for(int i=0;i<n;++i)
#define REP1(i,a,b) for(int i=a;i<=b;++i)
#define em emplace_back
#define lb(x) x&-x
#define pll pair<ll,ll>
#define mkp make_pair
#define endl "\n"

const int z=200005;
int n,q,seg[2][z<<2],a[z],b[z];
#define ls rt<<1
#define rs rt<<1|1

void build(int l,int r,int rt){
    if(l==r){
        seg[0][rt]=a[l]-a[l-1];
        seg[1][rt]=b[l]-b[l-1];
        return;
    }
    int mid=l+r>>1;
    build(l,mid,ls); build(mid+1,r,rs);
    seg[0][rt]=__gcd(seg[0][ls],seg[0][rs]);
    seg[1][rt]=__gcd(seg[1][ls],seg[1][rs]);
}

int qry(int l,int r,int ql,int qr,int rt,int id){
    if(ql<=l&&r<=qr) return seg[id][rt];
    int mid=l+r>>1, ret=0;
    if(ql<=mid) ret=qry(l,mid,ql,qr,ls,id);
    if(qr>mid) ret=__gcd(ret,qry(mid+1,r,ql,qr,rs,id));
    return ret;
}

signed main(){valder
    cin>>n>>q;
    for(int i=1;i<=n;++i) cin>>a[i];
    for(int i=1;i<=n;++i) cin>>b[i];
    build(1,n,1);
    for(int h1,h2,w1,w2,ans;q--;){
        cin>>h1>>h2>>w1>>w2;
        ans=a[h1]+b[w1];
        if(h1<h2) ans=__gcd(ans,qry(1,n,h1+1,h2,1,0));
        if(w1<w2) ans=__gcd(ans,qry(1,n,w1+1,w2,1,1));
        cout<<abs(ans)<<endl;
    }
}
