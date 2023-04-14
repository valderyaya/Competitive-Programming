//#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#include<bits/stdc++.h>
//#include<bits/extc++.h>
//using namespace __gnu_pbds;
using namespace std;
#define F first
#define S second
#define REP(i,n) for(int i=0;i<(n);++i)
#define REP1(i,a,b) for(int i=(a);i<=(b);++i)
#define em emplace_back
#define mkp make_pair
#define pii pair<int,int>
#define pll pair<ll,ll>
#define Rosario ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//#define lb(x) (x&-x)

const int z=1e5+5;
int n,m,dfn[z],low[z],tme;
vector<pii> v[z],ans;
bitset<z> vis;
bitset<z<<1> in;
void dfs(int x,int p){
    vis[x]=1;
    dfn[x]=low[x]=++tme;
    for(auto &i:v[x]){
        if(i.F!=p){
            if(!in[i.S]){
                in[i.S]=1;
                ans.em(x,i.F);
            }
            if(!vis[i.F]){
                dfs(i.F,x);
                low[x]=min(low[x],low[i.F]);
                if(dfn[x]<low[i.F]){
                    cout<<"IMPOSSIBLE";
                    exit(0);
                }
            }else low[x]=min(low[x],dfn[i.F]);
        }
    }
}
signed main(){Rosario
    cin>>n>>m;
    for(int x,y;m--;){
        cin>>x>>y;
        v[x].em(y,m);
        v[y].em(x,m);
    }
    dfs(1,0);
    for(int i=1;i<=n;++i) if(!vis[i]) return cout<<"IMPOSSIBLE",0;
    for(auto &i:ans) cout<<i.F<<' '<<i.S<<"\n";
    return 0;
}
