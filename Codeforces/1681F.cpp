#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define ll long long
#define em emplace_back
#define ls rt<<1
#define rs ls|1
#define mkp make_pair
#define F first
#define S second

const int z=5e5+5;
vector<pii> g[z],seg[z<<2];
vector<int> st;
int pa[z],n,sz[z],cnt;
ll ans;
int fin(int x){while(x^pa[x]) x=pa[x]; return x;}
void add(int l,int r,int ql,int qr,int rt, pii x){
    if(ql<=l&&r<=qr) return seg[rt].em(x),void();
    int mid=l+r>>1;
    if(ql<=mid) add(l,mid,ql,qr,ls,x);
    if(qr>mid) add(mid+1,r,ql,qr,rs,x);
}
void dfs(int l,int r,int rt){
    int now=st.size();
    for(auto &i:seg[rt]){
        int x=fin(i.F), y=fin(i.S);
        if(x==y) continue;
        if(sz[x]>sz[y]) x^=y^=x^=y;
        st.em(x);
        pa[x]=y, sz[y]+=sz[x];
    }
    if(l==r) for(auto &i:g[l]) ans+=(ll)sz[fin(i.F)]*sz[fin(i.S)];
    else{
        int mid=l+r>>1;
        dfs(l,mid,ls), dfs(mid+1,r,rs);
    }
    while(st.size()>now){
        int x=st.back(); st.pop_back();
        sz[pa[x]]-=sz[x], pa[x]=x;
    }
}
signed main(){
    cin>>n;
    pa[n]=n, sz[n]=1;
    for(int x,y,v,i=1;i<n;++i){
        pa[i]=i, sz[i]=1;
        cin>>x>>y>>v;
        g[v].em(x,y);
        if(v>1) add(1,n,1,v-1,1,mkp(x,y));
        if(v<n) add(1,n,v+1,n,1,mkp(x,y));
    }
    dfs(1,n,1);
    cout<<ans<<'\n';
}
