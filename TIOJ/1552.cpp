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

const int z=5e6+5,zz=1e6+5;
struct edge{
    int to,nxt,w;
}e[z];
int h[zz],fa[zz],cnt,n,m;
ll dis[zz];
void add(int u,int v,int w){
    e[++cnt]=edge{v,h[u],w};
    h[u]=cnt;
}
priority_queue<pll,vector<pll>,greater<pll> > q;
void dijk(){
    REP1(i,2,n+1) dis[i]=1e18;
    q.emplace(0,1);
    ll x,d;
    while(!q.empty()){
        tie(d,x)=q.top(); q.pop();
        if(d!=dis[x]) continue;
        for(int i=h[x];i;i=e[i].nxt){
            int v=e[i].to;
            if(d+e[i].w<dis[v]){
                fa[v]=x;
                dis[v]=d+e[i].w;
                q.emplace(dis[v],v);
            }else if(d+e[i].w==dis[v]){
                if(x<fa[v]) fa[v]=x;
            }
        }
    }
}
void print(int x){
    if(!x)return;
    print(fa[x]);
    if(x!=1) cout<<"-"<<x;
    else cout<<x;
}
signed main(){Rosario
    cin>>n>>m;
    for(int x,y,w;m;--m){
        cin>>x>>y>>w;
        add(x,y,w);
    }
    dijk();
    cout<<dis[n+1]<<"\n";
    print(n+1);
    return 0;
}
