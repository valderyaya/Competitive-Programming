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
#define Aincrad ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define lb(x) (x&-x)

ll a[65],n,m,h[50005],cnt,xo[50005];
struct edge{ll to,nxt,w;}e[200005];
bitset<50005> vis;
void add(ll u,ll v,ll w){
    e[++cnt]=edge{v,h[u],w};
    h[u]=cnt;
}
void insert(ll x){
    if(!x) return;
    for(ll i=63;~i;--i)
        if(x>>i&1){
            if(!a[i]) return a[i]=x,void();
            x^=a[i];
        }
}
ll qry(ll x){
    for(ll i=63;~i;--i)
        x=max(x,x^a[i]);
    return x;
}
void dfs(ll x,ll now){
    xo[x]=now;
    vis[x]=1;
    for(ll i=h[x];i;i=e[i].nxt)
        if(!vis[e[i].to]) dfs(e[i].to,xo[x]^e[i].w);
        else insert(e[i].w^now^xo[e[i].to]);
}
signed main(){Aincrad
    cin>>n>>m;
    for(ll x,y,z;m--;){
        cin>>x>>y>>z;
        add(x,y,z);
        add(y,x,z);
    }
    dfs(1,0);
    cout<<qry(xo[n])<<"\n";
    return 0;
}
