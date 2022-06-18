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
struct edge{int to,nxt,w;}e[10505];
const int z=205;
int n,m,cnt=1,st,ed,h[z],d[z],cur[z];
void add(int u,int v,int w){
    e[++cnt]=edge{v,h[u],w};
    h[u]=cnt;
}
queue<int> q;
bool bfs(){
    REP1(i,1,n) cur[i]=h[i],d[i]=0;
    d[st]=1; q.emplace(st);
    while(!q.empty()){
        int x=q.front(); q.pop();
        for(int i=h[x];i;i=e[i].nxt){
            int v=e[i].to;
            if(e[i].w&&!d[v]){
                q.emplace(v);
                d[v]=d[x]+1;
            }
        }
    }
    return d[ed];
}
int dfs(int x,int flow){
    if(x==ed||flow==0) return flow;
    int res=0,k;
    for(int &i=cur[x];i;i=e[i].nxt){
        int v=e[i].to;
        if(e[i].w&&d[v]==d[x]+1){
            k=dfs(v,min(flow,e[i].w));
            if(k){
                e[i].w-=k, e[i^1].w+=k;
                res+=k, flow-=k;
            }
        }
        if(!flow) break;
    }
    return res;
}
int dinic(){
    int res=0;
    while(bfs()) res+=dfs(st,1e18);
    return res;
}
signed main(){Rosario
    cin>>n>>m>>st>>ed;
    for(int x,y,w;m;--m){
        cin>>x>>y>>w;
        add(x,y,w);
        add(y,x,0);
    }
    cout<<dinic()<<"\n";
    return 0;
}
