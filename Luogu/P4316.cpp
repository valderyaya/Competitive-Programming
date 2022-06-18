//#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#include<bits/stdc++.h>
//#include<bits/extc++.h>
//using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
#define F first
#define S second
#define pb push_back
#define em emplace_back
#define REP(i,n) for(register int i=0;i<(n);++i)
#define REP1(i,a,b) for(register int i=(a);i<=(b);++i)
#define ALL(x) (x).begin(),(x).end()
#define pii pair<int,int>
#define pll pair<ll,ll>
#define Rosario ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//#define lb(x) (x&-x)

const int z=1e5+5;
struct edge{int to,nxt,w;}e[z<<1];
int in[z],n,m,h[z],cnt,dg[z];
double f[z];
void add(int u,int v,int w){
    e[++cnt]=edge{v,h[u],w};
    h[u]=cnt;
}
queue<int> q;
void topo(){
    q.emplace(n);
    while(!q.empty()){
        int x=q.front(); q.pop();
        for(int i=h[x];i;i=e[i].nxt){
            int v=e[i].to;
            f[v]+=(f[x]+e[i].w)/dg[v];
            if(--in[v]==0) q.emplace(v);
        }
    }
}
int main(){
    cin>>n>>m;
    for(int x,y,c;m;--m) cin>>x>>y>>c,add(y,x,c),++in[x],++dg[x];
    topo(); cout<<fixed<<setprecision(2)<<f[1]<<"\n";
    return 0;
}
