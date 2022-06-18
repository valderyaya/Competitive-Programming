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

struct edge{int to,nxt,w;}e[200005];
int n,m,h[5005],cnt,d[5005],d2[5005];
void add(int u,int v,int w){
    e[++cnt]=edge{v,h[u],w};
    h[u]=cnt;
}
void dijkstra(){
    priority_queue<pii,vector<pii> ,greater<pii>>q;
    REP1(i,1,n) d[i]=d2[i]=1e9;
    q.emplace(0,1);
    while(!q.empty()){
        pii o=q.top(); q.pop();
        if(o.F>d2[o.S]) continue;
        for(int i=h[o.S];i;i=e[i].nxt){
            int v=e[i].to;
            if(d[v]>o.F+e[i].w) d2[v]=d[v],d[v]=o.F+e[i].w,q.emplace(d[v],v);
            else if(d2[v]>o.F+e[i].w&&o.F+e[i].w!=d[v]) d2[v]=e[i].w+o.F,q.emplace(d2[v],v);
        }
    }
    cout<<d2[n]<<"\n";
}
int main(){Rosario
    cin>>n>>m;
    for(int i=0,x,y,z;i<m;++i) {
        cin>>x>>y>>z;
        add(x,y,z);
        add(y,x,z);
    }
    dijkstra();
    return 0;
}
