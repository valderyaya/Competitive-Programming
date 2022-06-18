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

int dfn[20005],low[20005],cnt,n,m;
vector<int> v[20005];
bool is[20005];
void dfs(int x,int rt){
    low[x]=dfn[x]=++cnt;
    int c=0;
    for(auto &i:v[x]){
        if(!dfn[i]){
            ++c;
            dfs(i,rt);
            low[x]=min(low[x],low[i]);
            if(dfn[x]<=low[i]&&x!=rt) is[x]=1;
        }else if(dfn[i]<dfn[x]) low[x]=min(low[x],dfn[i]);
    }
    if(x==rt&&c>1) is[x]=1;
}
signed main(){Rosario
    cin>>n>>m; int ans=0;
    for(int x,y;m;--m) cin>>x>>y,v[x].em(y),v[y].em(x);
    REP1(i,1,n) if(!dfn[i]) dfs(i,i);
    REP1(i,1,n) if(is[i])++ans;
    cout<<ans<<"\n";
    REP1(i,1,n) if(is[i]) cout<<i<<' ';
    return 0;
}
