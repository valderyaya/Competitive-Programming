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

const int z=1e5+5,zz=3e5+5,mod=1e9+7;
struct edge{int to,nxt;}e[zz];
int n,m,w[z],h[z],tot,col[z],we[z],cl,cnt=0,low[z],dfn[z],cc[z];
ll ans=1,sum=0;
void add(int u,int v){
    e[++cnt]=edge{v,h[u]};
    h[u]=cnt;
}
stack<int> st;
bitset<z> vis;
void dfs(int x){
    dfn[x]=low[x]=++tot;
    st.emplace(x); vis[x]=1;
    for(int i=h[x];i;i=e[i].nxt){
        int v=e[i].to;
        if(!dfn[v]) dfs(v),low[x]=min(low[x],low[v]);
        else if(vis[v]) low[x]=min(low[x],dfn[v]);
    }
    if(dfn[x]==low[x]){we[++cl]=mod;
        for(int u=0;u!=x;st.pop()){u=st.top();
            if(w[u]<we[cl]) we[cl]=w[u],cc[cl]=1;
            else if(w[u]==we[cl]) cc[cl]++;
            vis[u]=0; col[u]=cl;
        }
    }
}
int main(){Rosario
    cin>>n;
    REP1(i,1,n) cin>>w[i];
    cin>>m; int x,y;
    while(m--) cin>>x>>y,add(x,y);
    REP1(i,1,n) if(!dfn[i]) dfs(i);
    REP1(i,1,cl) sum+=we[i],ans=ans*cc[i]%mod;
    cout<<sum<<' '<<ans;
    return 0;
}
