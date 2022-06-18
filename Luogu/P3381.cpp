//#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#include<bits/stdc++.h>
//#include<bits/extc++.h>
//using namespace __gnu_pbds;
using namespace std;
#define F first
#define S second
typedef long long ll;
#define REP(i,n) for(register int i=0;i<(n);++i)
#define REP1(i,a,b) for(register int i=(a);i<=(b);++i)
#define em emplace_back
#define mkp make_pair
#define pb push_back
#define ALL(x) (x).begin(),(x).end()
#define pii pair<int,int>
#define pll pair<ll,ll>
#define Rosario ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//#define lb(x) (x&-x)

#define int ll
const int z=5e3+5,zz=5e4+5;
struct edge{int to,nxt,w,c;}e[zz<<1];
int n,cost,m,st,ed,cnt=1,h[z],ans,cur[z],d[z];
void add(int u,int v,int w,int c){
    e[++cnt]=edge{v,h[u],w,c};
    h[u]=cnt;
}
queue<int> q;
bool vis[z];
bool spfa(){
    REP1(i,1,n) d[i]=1e18,vis[i]=0,cur[i]=h[i];
    q.emplace(st); d[st]=0; vis[st]=1;
    while(!q.empty()){
        int x=q.front(); q.pop(); vis[x]=0;
        for(int i=h[x];i;i=e[i].nxt){
            int v=e[i].to;
            if(e[i].w&&d[x]+e[i].c<d[v]){
                d[v]=d[x]+e[i].c;
                if(!vis[v])  vis[v]=1,q.emplace(v);
            }
        }
    }
    return d[ed]!=1e18;
}
int dfs(int x,int flow){
    if(x==ed||!flow) return flow;
    int res=0,k; vis[x]=1;
    for(int &i=cur[x];i;i=e[i].nxt){
        int v=e[i].to;
        if(!vis[v]&&d[v]==d[x]+e[i].c&&e[i].w){
            k=dfs(v,min(flow,e[i].w));
            if(k){
                cost+=e[i].c*k; flow-=k, res+=k;
                e[i].w-=k ,e[i^1].w+=k;
            }
        }
        if(!flow) break;
    }
    return res;
}
void dinic(){
    while(spfa()) {
        memset(vis,0,sizeof(vis));
        ans+=dfs(st,1e18);
    }
    cout<<ans<<' '<<cost<<"\n";
}
signed main(){Rosario
    cin>>n>>m>>st>>ed;
    for(int x,y,w,c;m;--m){
        cin>>x>>y>>w>>c;
        add(x,y,w,c);
        add(y,x,0,-c);
    }
    dinic();
    return 0;
}
