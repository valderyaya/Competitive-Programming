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

const int inf=1e9,st=0,ed=205;
struct edge{int to,nxt,cost,flow;}e[50000];
int cnt=1,n,m,dis[210],h[210],cur[210],cst;
void add(int u,int v,int w,int cost){
    e[++cnt]=edge{v,h[u],cost,w};
    h[u]=cnt;
}
queue<int> q;
bitset<210> vis;
bool spfa(){
    REP1(i,st,ed) dis[i]=inf,cur[i]=h[i];
    vis[st]=1; q.emplace(st); dis[st]=0;
    while(!q.empty()){
        int x=q.front(); vis[x]=0; q.pop();
        for(int i=h[x];i;i=e[i].nxt)
            if(e[i].flow&&dis[e[i].to]>dis[x]+e[i].cost){
                dis[e[i].to]=dis[x]+e[i].cost;
                if(!vis[e[i].to]) q.emplace(e[i].to),vis[e[i].to]=1;
            }
    }
    return dis[ed]!=inf;
}
int dfs(int x,int flow){
    if(x==ed) return flow;
    int sum=0,k;
    vis[x]=1;
    for(int &i=cur[x];i;i=e[i].nxt)
        if(!vis[e[i].to]&&e[i].flow&&dis[e[i].to]==dis[x]+e[i].cost){
            k=dfs(e[i].to,min(flow,e[i].flow));
            if(k){
                flow-=k, cst+=e[i].cost*k;
                e[i].flow-=k, sum+=k; e[i^1].flow+=k;
            }
            if(!flow) break;
        }
    vis[x]=0;
    return sum;
}
int solve(){
    int res=0;
    while(spfa()) res+=dfs(st,inf);
    return res;
}
int w[101],cp[101][101],need[101];
void build(int c){
    cst=0; cnt=1;
    REP1(i,1,n) add(st,i,w[i],0),add(i,st,0,0);
    REP1(i,1,m) add(i+n,ed,need[i],0),add(ed,i+n,0,0);
    REP1(i,1,n) REP1(j,1,m) add(i,j+n,need[j],cp[i][j]*c),add(j+n,i,0,-cp[i][j]*c);
}
int main(){Rosario
    cin>>n>>m;
    int x;
    REP1(i,1,n) cin>>w[i];
    REP1(i,1,m) cin>>need[i];
    REP1(i,1,n) REP1(j,1,m) cin>>cp[i][j];
    build(1);
    solve();
    cout<<cst<<"\n";
    memset(h,0,sizeof(h));
    build(-1);
    solve();
    cout<<-cst<<"\n";
    return 0;
}
