//#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#include<bits/stdc++.h>
//#include<bits/extc++.h>
//using namespace __gnu_pbds;
using namespace std;
#define F first
#define S second
typedef long long ll;
#define REP(i,n) for(int i=0;i<(n);++i)
#define REP1(i,a,b) for(int i=(a);i<=(b);++i)
#define em emplace_back
#define mkp make_pair
#define pb push_back
#define ALL(x) (x).begin(),(x).end()
#define pii pair<int,int>
#define pll pair<ll,ll>
#define Rosario ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//#define lb(x) (x&-x)

int dis[105],n,st,ed,h[105],cnt=0;
struct edge{int to,nxt,w;}e[50000];
void add(int u,int v,int w){
    e[++cnt]=edge{v,h[u],w};
    h[u]=cnt;
}
int dijk(){ int d,x;
    REP1(i,1,n) dis[i]=20000;
    priority_queue<pii,vector<pii>,greater<pii>> q;
    q.emplace(mkp(dis[st]=0,st));
    while(!q.empty()){
        tie(d,x)=q.top(); q.pop();
        if(dis[x]!=d) continue;
        for(int i=h[x];i;i=e[i].nxt){
            int v=e[i].to;
            if(dis[v]>d+e[i].w) dis[v]=d+e[i].w,q.emplace(mkp(dis[v],v));
        }
    }
    return (dis[ed]==20000?-1:dis[ed]);
}
int main(){Rosario
    cin>>n>>st>>ed;
    for(int i=1,k,x;i<=n;++i){
        cin>>k;
        for(int j=0;j<k;++j) cin>>x,add(i,x,(j?1:0));
    }cout<<dijk()<<"\n";
    return 0;
}
