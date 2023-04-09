//#pragma GCC optimize("unroll-loops, no-stack-protector, Ofast")
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

const int maxn=50005;
struct edge{
    int to,nxt;
}e[maxn<<2],e2[maxn<<2];
int qry,cnt,dfn[maxn],tot,m,low[maxn],bel[maxn],n,color,h[maxn],h2[maxn],in[maxn];
void add(int u,int v,int id){
    if(id){
        e[++cnt]=edge{v,h[u]};
        h[u]=cnt;
    }else{
        e2[++cnt]=edge{v,h2[u]};
        h2[u]=cnt;
    }
}
stack<int,vector<int>> st;
bitset<maxn> rea[maxn];
void dfs(int x){
    low[x]=dfn[x]=++tot;
    in[x]=1;
    st.emplace(x);
    for(int v,i=h[x];i;i=e[i].nxt){
        v=e[i].to;
        if(!dfn[v]){
            dfs(v);
            low[x]=min(low[x],low[v]);
        }else if(in[v]&&dfn[v]<dfn[x]) low[x]=min(low[x],dfn[v]);
    }
    if(low[x]==dfn[x]){
        ++color;
        for(int u=0;u!=x;st.pop()){
            u=st.top();
            in[u]=0;
            bel[u]=color;
        }
    }
}
signed main(){StarBurstStream
    cin>>n>>m>>qry;
    for(int x,y;m--;){
        cin>>x>>y;
        add(x,y,1);
    }
    for(int i=1;i<=n;++i) if(!dfn[i]) dfs(i);
    queue<int> q;
    for(int i=1;i<=n;++i)
        for(int j=h[i];j;j=e[j].nxt)
            if(bel[i]!=bel[e[j].to]){
                ++in[bel[i]];
                add(bel[e[j].to],bel[i],0);
            }
    for(int i=1;i<=color;++i) if(!in[i]){
        rea[i].set(i);
        q.emplace(i);
    }
    while(!q.empty()){
        int x = q.front(); q.pop();
        for(int v,i=h2[x];i;i=e2[i].nxt){
            v=e2[i].to;
            rea[v]|=rea[x];
            if(--in[v]==0){
                rea[v].set(v);
                q.emplace(v);
            }
        }
    }
    for(int x,y;qry--;){
        cin>>x>>y;
        cout<<(rea[bel[x]][bel[y]]?"YES":"NO")<<"\n"; 
    }
    return 0;
}
