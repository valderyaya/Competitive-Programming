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
//#define line cout<<"-------------------------\n";

const int z=1e4+5,zz=1e5+5;
struct edge{int to,nxt;}e[zz],e2[zz];
int low[z],val[z],col[z],cl=0,sum[z],dfn[z],tot=0,n,m,h[z],cnt=0,cnt2=0,h2[z],in[z],ans[z];
bitset<z> vis;
stack<int> st;
void add(int u,int v){
    e[++cnt]=edge{v,h[u]};
    h[u]=cnt;
}
void add2(int u,int v){
    e2[++cnt2]=edge{v,h2[u]};
    h2[u]=cnt2;
}
void dfs(int x){
    dfn[x]=low[x]=++tot;
    st.emplace(x); vis[x]=1;
    for(int i=h[x];i;i=e[i].nxt){
        int v=e[i].to;
        if(!dfn[v]){
            dfs(v);
            low[x]=min(low[x],low[v]);
        }else if(vis[v]) low[x]=min(low[x],dfn[v]);
    }
    if(dfn[x]==low[x]){++cl;
        for(int u=-1;u!=x;st.pop()) u=st.top(),sum[cl]+=val[u],vis[u]=0,col[u]=cl;
    }
}
int topo(){
    queue<int> q; vis.reset(); int mx=0;
    REP1(i,1,cl) if(!in[i]) q.emplace(i),ans[i]=sum[i],mx=max(mx,sum[i]);
    while(!q.empty()){
        int x=q.front(); q.pop();
        for(int i=h2[x];i;i=e2[i].nxt){
            int v=e2[i].to;
            ans[v]=max(ans[v],ans[x]+sum[v]);
            mx=max(mx,ans[v]);
            if(--in[v]==0) q.emplace(v);
        }
    }
    return mx;
}
int main(){Rosario
    cin>>n>>m;
    REP1(i,1,n) cin>>val[i];
    int x,y;
    while(m--){
        cin>>x>>y;
        add(x,y);
    }
    REP1(i,1,n) if(!dfn[i]) dfs(i);
    REP1(i,1,n) for(int j=h[i];j;j=e[j].nxt) if(col[i]!=col[e[j].to]) add2(col[i],col[e[j].to]),++in[col[e[j].to]];
    cout<<topo()<<"\n";
    return 0;
}
