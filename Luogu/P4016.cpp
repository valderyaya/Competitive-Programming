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

const int inf=1e9;
struct edge{int to,w,cost,nxt;}e[20050];
int s,t,h[105],cur[105],cnt=1,n,a[105],dis[105],ans=0;
void add(int u,int v,int w,int cost){
    e[++cnt]=edge{v,w,cost,h[u]};
    h[u]=cnt;
}
bitset<105> vis;
queue<int> q;
bool spfa(){
    REP1(i,0,n+1) dis[i]=inf,cur[i]=h[i];
    dis[s]=0; q.emplace(s); vis[s]=1;
    while(!q.empty()){
        int x=q.front();q.pop(); vis[x]=0;
        for(int i=h[x];i;i=e[i].nxt){
            int v=e[i].to;
            if(e[i].w&&dis[v]>dis[x]+e[i].cost){
                dis[v]=dis[x]+e[i].cost;
                if(!vis[v]) q.emplace(v),vis[v]=1;
            }
        }
    }
    return dis[t]!=inf;
}
int dfs(int x,int flow){
    if(x==t) return flow;
    int sum=0; vis[x]=1;
    for(int &i=cur[x];i;i=e[i].nxt){
        int v=e[i].to;
        if(!vis[v]&&e[i].w&&dis[v]==dis[x]+e[i].cost){
            int k=dfs(v,min(flow,e[i].w));
            if(k) e[i].w-=k,e[i^1].w+=k,flow-=k,sum+=k,ans+=k*e[i].cost;
            if(!flow) break;
        }
    }
    vis[x]=0;
    return sum;
}
void dinic(){while(spfa()) dfs(s,inf);}
int main(){Rosario
    cin>>n; s=0,t=n+1;
    int sum=0;
    REP1(i,1,n){
       cin>>a[i],sum+=a[i];
       if(i!=1) add(i,i-1,inf,1),add(i-1,i,0,-1);
       if(i!=n) add(i,i+1,inf,1),add(i+1,i,0,-1);
    }sum/=n;
    add(1,n,inf,1),add(n,1,0,-1);
    add(n,1,inf,1),add(1,n,0,-1);
    REP1(i,1,n){
        a[i]-=sum;
        if(a[i]<0) add(i,t,-a[i],0),add(t,i,0,0);
        else add(s,i,a[i],0),add(i,s,0,0);
    }
    dinic();
    cout<<ans<<"\n";
//    system("pause");
    return 0;
}
