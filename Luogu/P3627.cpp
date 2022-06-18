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
#define wait system("pause");

const int z=5e5+5;
struct edge{int to,nxt;}e[z],e2[z];
int h2[z],h[z],cnt2=0,dfn[z],tot=0,s,low[z],w[z],cnt=0,col=0,cl[z],sum[z],n,m,dp[z],in[z];
stack<int> st;
bitset<z> vis,pub,bar;
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
    vis[x]=1; st.emplace(x);
    for(int i=h[x];i;i=e[i].nxt){
        int v=e[i].to;
        if(!dfn[v]) dfs(v),low[x]=min(low[x],low[v]);
        else if(vis[v]) low[x]=min(low[x],dfn[v]);
    }
    if(low[x]==dfn[x]){++col;
        for(int u=0;u!=x;st.pop()) {
            u=st.top(),cl[u]=col,vis[u]=0,sum[col]+=w[u];
            if(pub[u]) bar[col]=1;
        }
    }
}
int topo(){
    queue<int> q; q.emplace(cl[s]);
    dp[cl[s]]=sum[cl[s]]; 
    while(!q.empty()){
        int x=q.front(); q.pop();
        for(int i=h2[x];i;i=e2[i].nxt){
            int v=e2[i].to;
            dp[v]=max(dp[v],dp[x]+sum[v]);
            if(--in[v]==0) q.emplace(v);
        }
    }
    int mx=0;
    REP1(i,1,col) if(bar[i]) mx=max(mx,dp[i]);
    return mx;
}
int main(){Rosario
    cin>>n>>m;
    int a,b,c;
    REP(i,m) cin>>a>>b,add(a,b);
    REP1(i,1,n) cin>>w[i];
    cin>>s>>a;
    while(a--) cin>>c,pub[c]=1;
    dfs(s);
    REP1(i,1,n){
        if(!cl[i]) continue;
        for(int j=h[i];j;j=e[j].nxt) if(cl[i]!=cl[e[j].to]) add2(cl[i],cl[e[j].to]),in[cl[e[j].to]]++;
    } 
    cout<<topo()<<"\n";
//    system("pause");
    return 0;
}
