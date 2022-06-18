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

const int z=405,inf=1e9;
struct edge{int to,nxt,w,c;}e[80005];
int cnt=1,dis[z],h[z],cur[z],n,m,cost=0,s,t;
void add(int u,int v,int w,int c){
    e[++cnt]=edge{v,h[u],w,c};
    h[u]=cnt;
}
bitset<z> vis;
queue<int> q;
bool bfs(){
    vis.reset(); vis[1]=1;
    REP1(i,1,n+n) dis[i]=inf,cur[i]=h[i];
    q.emplace(s); dis[s]=0;
    while(!q.empty()){
        int x=q.front();q.pop(); vis[x]=0;
        for(int i=h[x];i;i=e[i].nxt){
            int v=e[i].to;
            if(e[i].w&&dis[v]>dis[x]+e[i].c){
                dis[v]=dis[x]+e[i].c;
                if(!vis[v]){
                    q.emplace(v);
                    vis[v]=1;
                }
            }
        }
    }
    return dis[t]!=inf;
}
int dfs(int x,int flow){
    if(x==t||!flow) return flow;
    vis[x]=1; int res=0;
    for(int &i=cur[x];i;i=e[i].nxt){
        int v=e[i].to;
        if(!vis[v]&&dis[v]==dis[x]+e[i].c&&e[i].w){
            int k=dfs(v,min(flow,e[i].w));
            if(k){
                e[i].w-=k,e[i^1].w+=k;
                cost+=k*e[i].c; res+=k; flow-=k;
            }
            if(!flow) break;
        }
    }
    vis[x]=0;
    return res;
}
void dinic(){
    int res=0;
    while(bfs()){
        vis.reset();
        res+=dfs(s,inf);
    }
    cout<<res<<' '<<cost<<"\n";
}
int main(){Rosario
    cin>>n>>m; s=n+1,t=n;
    REP1(i,1,n) add(i,i+n,1,0),add(i+n,i,0,0);
    int x,y,c;
    while(m--){
        cin>>x>>y>>c;
        add(x+n,y,1,c);
        add(y,x+n,0,-c);
    }
    dinic();
    return 0;
}
