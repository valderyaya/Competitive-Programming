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

struct edge{int to,nxt;}e[20005];
int n,cnt,h[10005],ord[10005],idx,fa[10005];
bitset<10005> vis,is;
void add(int u,int v){
    e[++cnt]=edge{v,h[u]};
    h[u]=cnt;
}
void dfs(int x){
    ord[idx++]=x; vis[x]=1;
    for(int i=h[x];i;i=e[i].nxt){
        int v=e[i].to;
        if(vis[v]) continue;
        fa[v]=x; dfs(v); 
    }
}
int solve(){
    int res=0;
    vis.reset();
    for(int i=n-1;i>=0;--i){
        int x=ord[i];
        if(!vis[x]){
            if(!is[fa[x]]){
                is[fa[x]]=1;
                ++res;
            }
            vis[x]=1;
            vis[fa[x]]=1;
            vis[fa[fa[x]]]=1;
        }
    }
    return res;
}
int main(){Rosario
    while(cin>>n){
        memset(h,0,sizeof(h)); fa[1]=1;
        int x,y; cnt=idx=0; vis.reset(),is.reset();
        REP(i,n-1) cin>>x>>y,add(x,y),add(y,x);
        dfs(1); cout<<solve()<<"\n";
    }
    return 0;
}
