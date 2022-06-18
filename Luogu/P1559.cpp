//#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#include<bits/stdc++.h>
//#include<bits/extc++.h>
//using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
#define F first
#define S second
#define pb push_back
#define REP(i,n) for(register int i=0;i<(n);++i)
#define REP1(i,a,b) for(register int i=(a);i<=(b);++i)
#define em emplace_back
#define ALL(x) (x).begin(),(x).end()
#define mkp make_pair
#define pii pair<int,int>
#define pll pair<ll,ll>
#define Rosario ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//#define lb(x) (x&-x)

struct edge{int to,nxt,w,c;}e[10000];
int ans,n,cnt=1,st=68,ed=69,p[70][70],q[70][70],h[70],d[70];
bitset<70> vis;
void add(int u,int v,int w,int c){
    e[++cnt]=edge{v,h[u],w,c};
    h[u]=cnt;
}
queue<int> qe;
bool spfa(){
    REP1(i,0,69) d[i]=-1e9;
    vis.reset(); vis[st]=1;
    d[st]=0; qe.emplace(st);
    while(!qe.empty()){
        int x=qe.front(); qe.pop(); vis[x]=0;
        for(int i=h[x];i;i=e[i].nxt){
            int v=e[i].to;
            if(e[i].w&&d[v]<d[x]+e[i].c){
                d[v]=d[x]+e[i].c;
                if(!vis[v]) qe.emplace(v),vis[v]=1;
            }
        }
    }
    return d[ed]!=-1e9;
}
int dfs(int x,int flow){
    if(x==ed||!flow) return flow;
    vis[x]=1; int k,res=0;
    for(int i=h[x];i;i=e[i].nxt){
        int v=e[i].to;
        if(!vis[v]&&e[i].w&&d[v]==d[x]+e[i].c){
            k=dfs(v,min(flow,e[i].w));
            if(k){
                ans+=k*e[i].c; res+=k;
                e[i].w-=k, e[i^1].w+=k;
                flow -=k;
            }
            if(!flow) break;
        }
    }
    vis[x]=0;
    return res;
}
void dinic(){
    while(spfa()) {
        vis.reset();
        dfs(st,(int)1e9);
    }
}
int main(){Rosario
    cin>>n;
    REP1(i,1,n) REP1(j,1,n) cin>>p[i][j];
    REP1(i,1,n) REP1(j,1,n) cin>>q[i][j];
    REP1(i,1,n){
        add(st,i,1,0);
        add(i,st,0,0);
        add(i+n,ed,1,0);
        add(ed,i+n,1,0);
    }
    REP1(i,1,n) REP1(j,1,n){
        add(i,j+n,1,p[i][j]*q[j][i]);
        add(j+n,i,0,-p[i][j]*q[j][i]);
    }
    dinic();
    cout<<ans<<"\n";
    return 0;
}
