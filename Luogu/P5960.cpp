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

const int z=5e3+500;
int n,m,d[z],cnt[z],h[z],c;
struct edge{int to,nxt,w;}e[z<<1];
void add(int u,int v,int w){
    e[++c]=edge{v,h[u],w};
    h[u]=c;
}
bool vis[z];
vector<pii> v[z];
void spfa(){
    queue<int> q; q.emplace(0); vis[0]=1;
    REP1(i,1,n) d[i]=1e9;
    while(!q.empty()){
        int x=q.front(); q.pop(); vis[x]=0;
        for(int i=h[x];i;i=e[i].nxt){
            int v=e[i].to;
            if(d[v]>d[x]+e[i].w){
                d[v]=d[x]+e[i].w;
                if(!vis[v]) q.emplace(v),vis[v]=1;
                if(++cnt[v]>n) cout<<"NO",exit(0);
            }
        }
    }
    REP1(i,1,n) cout<<d[i]<<' ';
}
signed main(){Rosario
    cin>>n>>m;
    for(int x,y,w;m;--m){
        cin>>x>>y>>w;
        add(y,x,w);
    }
    REP1(i,1,n) add(0,i,0);
    spfa();
    return 0;
}
