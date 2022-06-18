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

const int z=1005;
struct edge{int to,nxt,w;}e[300000];
int d[z],n,h[z],cnt,c[z],m,t;
void add(int u,int v,int w){
    e[++cnt]=edge{v,h[u],w};
    h[u]=cnt;
}
queue<int> q;
bitset<z> vis;
void init(){
    cnt=0; vis.reset();
    memset(h,0,sizeof(h));
    memset(c,0,sizeof(c));
    memset(d,0x3f,sizeof(d));
}
bool spfa(){
    while(!q.empty()) q.pop();
    q.emplace(n+1); 
    vis[n+1]=1; d[n+1]=0;
    while(!q.empty()){
        int x=q.front(); q.pop(); vis[x]=0;
        for(int i=h[x];i;i=e[i].nxt){
            int v=e[i].to;
            if(d[v]>d[x]+e[i].w){
                d[v]=e[i].w+d[x];
                if(!vis[v]) q.emplace(v),vis[v]=1;
                if(++c[v]>n) return 0;
            }
        }
    }
    return 1;
}
int main(){Rosario
    cin>>t;
    while(t--){
        init();
        cin>>n>>m;
        REP1(i,0,n) add(n+1,i,0);
        for(int a,b,w;m;--m){
            cin>>a>>b>>w;--a;
            add(a,b,w);
            add(b,a,-w);
        }
        cout<<(spfa()?"true":"false")<<"\n";
    }
    return 0;
}
