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

const int z=1e5+5;
struct edge{int to,nxt;}e[z];
int low[z],n,m,h[z],tot=0,dfn[z]={},cnt=0,in[z],col[z]={},cl=0;
void add(int u,int v){
    e[++cnt]=edge{v,h[u]};
    h[u]=cnt;
}
stack<int> st;
bitset<z> vis;
void dfs(int x){
    low[x]=dfn[x]=++tot;
    vis[x]=1;st.emplace(x);
    for(int i=h[x];i;i=e[i].nxt){
        int v=e[i].to;
        if(!dfn[v]) dfs(v),low[x]=min(low[x],low[v]);
        else if(vis[v]) low[x]=min(low[x],dfn[v]);
    }
    if(low[x]==dfn[x]){++cl;
        for(int u=0;u!=x;st.pop()) u=st.top(),vis[u]=0,col[u]=cl;
    }
}

int main(){Rosario
    cin>>n>>m;
    int x,y;
    while(m--) cin>>x>>y,add(x,y);
    REP1(i,1,n) if(!dfn[i]) dfs(i);
    REP1(i,1,n)
        for(int j=h[i];j;j=e[j].nxt) if(col[i]!=col[e[j].to]) in[col[e[j].to]]++;
    x=0;
    REP1(i,1,cl) if(!in[i]) ++x;
    cout<<x<<"\n";
    return 0;
}
