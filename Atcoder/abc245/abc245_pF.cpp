#pragma GCC optimize("O2")
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

const int z=2e5+5;
int n,m,dfn[z],low[z],cnt,col[z],cl,ans,sz[z];
vector<int> v[z],st,v2[z];
bitset<z> vis,ck;
void dfs(int x){
    dfn[x]=low[x]=++cnt;
    st.em(x); vis[x]=1;
    for(auto &i:v[x])
        if(!dfn[i]) dfs(i), low[x]=min(low[x],low[i]);
        else if(vis[i]) low[x]=min(low[x],dfn[i]);
    if(low[x]==dfn[x]){
        ++cl;
        for(int u=-1;u!=x;st.pop_back()){
            u=st.back();
            ++sz[cl];
            vis[u]=0, col[u]=cl;
        }
    }
}
void dfs2(int x){
    vis[x]=1;
    if(sz[x]>1) ck[x]=1;
    for(auto &i:v2[x]){
        if(!vis[i]) dfs2(i);
        if(ck[i]) ck[x]=1;
    }
}
signed main(){valder
    cin>>n>>m;
    for(int x,y;m--;){
        cin>>x>>y;
        v[x].em(y);
    }
    for(int i=1;i<=n;++i) if(!dfn[i]) dfs(i);
    for(int i=1;i<=n;++i) 
        for(auto &j:v[i]) 
            if(col[i]!=col[j])
                v2[col[i]].em(col[j]);
    for(int i=1;i<=cl;++i) if(!vis[i]) dfs2(i);
    for(int i=1;i<=n;++i) if(ck[i]) ans+=sz[i];
    cout<<ans;
}
