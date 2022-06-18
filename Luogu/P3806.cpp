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

const int z=1e4+5;
struct edge{int to,nxt,w;}e[z<<1];
int n,h[z],rt,cnt,m,qry[105],d[z],mx[z],sum;
bool vis[z],pp[10000005]={1},res[105];
void add(int u,int v,int w){
    e[++cnt]=edge{v,h[u],w};
    h[u]=cnt;
}
void calrt(int x,int p){
    mx[x]=0, d[x]=1;
    for(int i=h[x];i;i=e[i].nxt){
        int v=e[i].to;
        if(v!=p&&!vis[v]){
            calrt(v,x);
            d[x]+=d[v];
            mx[x]=max(mx[x],d[v]);
        }
    }
    mx[x]=max(mx[x],sum-mx[x]);
    if(mx[rt]>mx[x]) rt=x;
}
int dd[z],id;
queue<int> tg;
void caldis(int x,int dis,int p){
    if(dis>10000000) return;
    dd[++id]=dis;
    for(int i=h[x];i;i=e[i].nxt){
        int v=e[i].to;
        if(v!=p&&!vis[v]) caldis(v,dis+e[i].w,x);
    }
}
void dfs(int x){
    vis[x]=1; tg.emplace(0); pp[0]=1;
    for(int i=h[x];i;i=e[i].nxt){
        int v=e[i].to;
        if(!vis[v]){
            caldis(v,e[i].w,x);
            REP1(j,1,id) REP1(k,1,m) if(qry[k]>=dd[j]&&pp[qry[k]-dd[j]]) res[k]=1;
            REP1(j,1,id) tg.emplace(dd[j]),pp[dd[j]]=1;
            id=0; 
        }
    }
    while(!tg.empty()) pp[tg.front()]=0,tg.pop();
    for(int i=h[x];i;i=e[i].nxt){
        int v=e[i].to;
        if(!vis[v]){
            sum=d[v];
            mx[rt=0]=1e9;
            calrt(v,x), calrt(rt,-1);
            dfs(rt);
        }
    }
}
signed main(){Rosario
    cin>>n>>m; sum=n;
    for(int x,y,w,i=1;i<n;++i) cin>>x>>y>>w,add(x,y,w),add(y,x,w);
    REP1(i,1,m) cin>>qry[i];
    mx[rt=0]=1e9;
    calrt(1,-1); calrt(rt,-1);
    dfs(rt);    
    REP1(i,1,m) cout<<(res[i]?"AYE":"NAY")<<"\n";
    return 0;
}
