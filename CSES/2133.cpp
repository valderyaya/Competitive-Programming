//#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#include<bits/stdc++.h>
//#include<bits/extc++.h>
//using namespace __gnu_pbds;
using namespace std;
#define F first
#define S second
#define REP(i,n) for(int i=0;i<(n);++i)
#define REP1(i,a,b) for(int i=(a);i<=(b);++i)
#define em emplace_back
#define mkp make_pair
#define pii pair<int,int>
#define pll pair<ll,ll>
#define Rosario ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//#define lb(x) (x&-x)


#define ls rt<<1
#define rs rt<<1|1
const int z=2e5+5;
vector<int> seg[z<<2];
map<pii,vector<pii>> mp;
int ans[z],n,m,t,q,pa[z],now,rk[z],u[z],v[z],top,cnow;
pii st[z];
inline int fin(int x){
    while(x^pa[x]) x=pa[x];
    return x;
}
void merge(int x,int y){
    if(x==y) return;
    if(rk[x]>rk[y]) x^=y^=x^=y;
    st[++top]=mkp(x,rk[x]==rk[y]);
    pa[x]=y; rk[y]+= rk[x]==rk[y]; --now;
}
void modify(int l,int r,int ql,int qr,int rt,int &val){
    if(ql>qr) return;
    if(ql<=l&&r<=qr) return seg[rt].em(val),void();
    int mid=l+r>>1;
    if(ql<=mid) modify(l,mid,ql,qr,ls,val);
    if(qr>mid) modify(mid+1,r,ql,qr,rs,val);
}
void dfs(int l,int r,int rt){
    int sz=top;
    for(auto &i:seg[rt]) merge(fin(u[i]),fin(v[i]));
    int mid=l+r>>1;
    if(l==r) ans[l]=now;
    else dfs(l,mid,ls),dfs(mid+1,r,rs);
    while(top>sz) rk[pa[st[top].F]]-=st[top].S,pa[st[top].F]=st[top].F,++now,--top;
}
int _find(int x){return pa[x]==x?x:pa[x]=_find(pa[x]);}
void _merge(int x,int y){
    if(x==y) return;
    pa[x]=y;
    --cnow;
}
int main(){Rosario
    int x; 
    cin>>n>>m>>q;
    cnow=n;
    REP1(i,1,n) pa[i]=i;
    REP1(i,1,m){ x=i+q;
        cin>>u[x]>>v[x];
        if(u[x]>v[x]) u[x]^=v[x]^=u[x]^=v[x];
        mp[{u[x],v[x]}].em(mkp(1,x));
        _merge(_find(u[x]),_find(v[x]));
    }
    cout<<cnow<<' ';
    REP1(i,1,n) pa[i]=i;
    REP1(i,1,q) {
        cin>>x>>u[i]>>v[i];
        if(u[i]>v[i]) u[i]^=v[i]^=u[i]^=v[i];
        if(x==1) mp[{u[i],v[i]}].em(mkp(i,i));
        else {
            auto &it=mp[{u[i],v[i]}];
            modify(1,q,it.back().F,i-1,1,i);
            it.pop_back();
        }
    }
    for(auto &i:mp) while(!i.S.empty()) modify(1,q,i.S.back().F,q,1,i.S.back().S),i.S.pop_back();
    now=n;  dfs(1,q,1);
    REP1(i,1,q) cout<<ans[i]<<' ';
    return 0;
}
