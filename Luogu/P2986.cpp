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

#define int ll
const int z=1e5+5;
int n,cnt,h[z],cs[z],sum;
struct edge{int to,nxt,w;}e[z<<1];
void add(int u,int v,int w){
    e[++cnt]=edge{v,h[u],w};
    h[u]=cnt;
}
ll dp[z],ans;
void dfs(int x,int p,int d){
    dp[1]+=d*cs[x];
    for(int i=h[x];i;i=e[i].nxt){
        if(e[i].to==p) continue;
        dfs(e[i].to,x,d+e[i].w);
        cs[x]+=cs[e[i].to];
    }
}
void dfs2(int x,int p){
    for(int i=h[x];i;i=e[i].nxt){
        if(e[i].to==p) continue;
        dp[e[i].to]=dp[x]+e[i].w*(sum-2*cs[e[i].to]);
        ans=min(ans,dp[e[i].to]);
        dfs2(e[i].to,x);
    }
}
signed main(){Aincrad
    cin>>n;
    REP1(i,1,n) cin>>cs[i],sum+=cs[i];
    for(int x,y,w,i=1;i<n;++i){
        cin>>x>>y>>w;
        add(x,y,w);
        add(y,x,w);
    }
    dfs(1,0,0);
    ans=dp[1];
    dfs2(1,0);
    cout<<ans<<"\n";
    return 0;
}
