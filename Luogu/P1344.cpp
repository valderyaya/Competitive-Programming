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

const int z=1001;
struct edge{int to,nxt,flow;}e[z<<1];
int n,m,cnt=1,h[35],cur[35],dis[35];
void add(int u,int v,int w){
    e[++cnt]=edge{v,h[u],w};
    h[u]=cnt;
}
queue<int> q;
bitset<35> vis;
bool bfs(){
    REP1(i,1,32) dis[i]=0,cur[i]=h[i];
    q.emplace(1); dis[1]=1;
    while(!q.empty()){
        int x=q.front(); q.pop();
        for(int i=h[x];i;i=e[i].nxt){
            int v=e[i].to;
            if(!dis[v]&&e[i].flow){
                dis[v]=dis[x]+1;
                q.emplace(v);
            }
        }
    }
    return dis[n];
}
ll dfs(int x,ll flow){
    if(x==n||flow==0) return flow;
    ll res=0; vis[x]=1;
    for(int &i=cur[x];i;i=e[i].nxt){
        int v=e[i].to;
        if(!vis[v]&&dis[v]==dis[x]+1&&e[i].flow){
            ll k=dfs(v,min(flow,(ll)e[i].flow));
            if(k){
                e[i].flow-=k, e[i^1].flow+=k;
                res+=k; flow-=k;
            }
            if(!flow) break;
        }
    }
    vis[x]=0;
    return res;
}
void dinic(){
    ll res=0;
    while(bfs()) 
        res+=dfs(1,1e18);
    cout<<res/z<<' '<<res%z<<"\n";
}
int main(){Rosario
    cin>>n>>m;
    for(int x,y,w;m;--m){
        cin>>x>>y>>w;
        add(x,y,z*w+1);
        add(y,x,0);
    }
    dinic();
    return 0;
}
