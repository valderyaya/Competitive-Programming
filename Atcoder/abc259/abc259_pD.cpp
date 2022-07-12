#pragma GCC optimize("O2")
#include<bits/stdc++.h>
using namespace std;
#define StarBurstStream ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
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

#define int ll
int n,pa[3001],sz[3001],sx,sy,tx,ty,r[3001];
pll a[3001];
vector<int> p,q;
int fin(int x){return x==pa[x]?x:pa[x]=fin(pa[x]);}
bool ck1(int i){return r[i]*r[i]==(sx-a[i].F)*(sx-a[i].F)+(sy-a[i].S)*(sy-a[i].S);}
bool ck2(int i){return r[i]*r[i]==(tx-a[i].F)*(tx-a[i].F)+(ty-a[i].S)*(ty-a[i].S);}
void un(int x,int y){
    x=fin(x), y=fin(y);
    if(x==y) return;
    if(sz[x]>sz[y]) swap(x,y);
    pa[x]=y, sz[y]+=sz[x];
}
bool dis(int i,int j){
    bool c1 = (a[i].F-a[j].F)*(a[i].F-a[j].F)+(a[i].S-a[j].S)*(a[i].S-a[j].S) <= (r[i]+r[j])*(r[i]+r[j]);
    bool c2 = (a[i].F-a[j].F)*(a[i].F-a[j].F)+(a[i].S-a[j].S)*(a[i].S-a[j].S) >= (r[i]-r[j])*(r[i]-r[j]);
    return c1&&c2;
}
signed main(){StarBurstStream
    cin>>n>>sx>>sy>>tx>>ty;
    for(int i=1;i<=n;++i){
        pa[i]=i; sz[i]=1;
        cin>>a[i].F>>a[i].S>>r[i];
        if(ck1(i)) p.em(i);
        if(ck2(i)) q.em(i);
    }
    for(int i=1;i<=n;++i)
        for(int j=i+1;j<=n;++j)
            if(dis(i,j)) un(i,j);
    for(auto &i:p)
        for(auto &j:q)
            if(fin(i)==fin(j)) return cout<<"Yes",0;
    cout<<"No";
}
