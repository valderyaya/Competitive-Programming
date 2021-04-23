//#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#include<bits/stdc++.h>
//#include<bits/extc++.h>
//using namespace __gnu_pbds;
using namespace std;
#define F first
#define S second
typedef long long ll;
#define REP(i,n) for(int i=0;i<(n);++i)
#define REP1(i,a,b) for(int i=(a);i<=(b);++i)
#define em emplace_back
#define mkp make_pair
#define pb push_back
#define ALL(x) (x).begin(),(x).end()
#define pii pair<int,int>
#define pll pair<ll,ll>
#define Rosario ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//#define lb(x) (x&-x)

const int z=1e6+5;
struct edge{int to,nxt;}e[z],e2[z];
int n,m,h[z],col[z],colour=0,h2[z],cnt=0,cnt2=0,dfn[z],tme=0,low[z],p[z],ans[z],in[z];
stack<int> st;
bitset<z> vis;
void add(int u,int v){
    e[++cnt]=edge{v,h[u]};
    h[u]=cnt;
}
void add2(int u,int v){
    e2[++cnt2]=edge{v,h2[u]};
    h2[u]=cnt2;
}
void dfs(int x){
    st.emplace(x); vis[x]=1; low[x]=dfn[x]=++tme;
    for(int i=h[x];i;i=e[i].nxt){
        int v=e[i].to;
        if(!dfn[v]) dfs(v),low[x]=min(low[x],low[v]);
        else if(vis[v]&&dfn[v]<low[x]) low[x]=dfn[v];
    }
    if(dfn[x]==low[x]){++colour;
        for(int i=-1;i!=x;st.pop()) i=st.top(),vis[i]=0,col[i]=colour,++p[colour];
    }
}
int solve(){
    int mx=0; queue<int> q;
    REP1(i,1,colour) if(in[i]==0) ans[i]=p[i],q.emplace(i);
    while(!q.empty()){
        int x=q.front(); q.pop();
        mx=max(mx,ans[x]);
        for(int i=h2[x];i;i=e2[i].nxt){
            int v=e2[i].to;
            ans[v]=max(ans[v],p[v]+ans[x]);
            if(--in[v]==0) q.emplace(v);
        }
    }
    return mx;
}
int main(){Rosario
    cin>>n>>m;
    int x,y;
    while(m--) cin>>x>>y,add(x,y);
    REP(i,n) if(!dfn[i]) dfs(i);
    REP(i,n) for(int j=h[i];j;j=e[j].nxt) if(col[i]!=col[e[j].to]) add2(col[i],col[e[j].to]),++in[col[e[j].to]];
    cout<<solve()<<"\n";
    return 0;
}
