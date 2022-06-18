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

const int z=101,inf=1e9;
struct edge{int to,nxt,w;}e[10000];
int n,m,s,t,cnt=1,dis[205],h[205],cur[205];
void add(int u,int v,int w){
    e[++cnt]=edge{v,h[u],w};
    h[u]=cnt;
}
queue<int> q;
bool bfs(){
    REP1(i,1,n+n) dis[i]=0,cur[i]=h[i];
    q.emplace(s); dis[s]=1;
    while(!q.empty()){
        int x=q.front(); q.pop();
        for(int i=h[x];i;i=e[i].nxt){
            int v=e[i].to;
            if(!dis[v]&&e[i].w) dis[v]=dis[x]+1,q.emplace(v);
        }
    }
    return dis[t];
}
bitset<205> vis;
int dfs(int x,int flow){
    if(x==t||flow==0) return flow;
    int res=0; vis[x]=1;
    for(int &i=cur[x];i;i=e[i].nxt){
        int v=e[i].to;
        if(!vis[v]&&dis[v]==dis[x]+1&&e[i].w){
            int k=dfs(v,min(e[i].w,flow));
            if(k){
                e[i].w-=k,e[i^1].w+=k;
                res+=k, flow-=k;
            }
            if(!flow) break;
        }
    }
    vis[x]=0;
    return res;
}
void dinic(){
    int sum=0;
    while(bfs()) sum+=dfs(s,inf);
    cout<<sum<<"\n";
}
int main(){Rosario
    cin>>n>>m>>s>>t;
    s+=n;
    REP1(i,1,n){
        add(i,i+n,1);
        add(i+n,i,0);
    }
    int x,y;
    while(m--){
        cin>>x>>y;
        add(x+n,y,inf);
        add(y,x+n,0);
        add(y+n,x,inf);
        add(x,y+n,0);
    }
    dinic();
    return 0;
}
