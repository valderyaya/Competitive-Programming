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

int dp[3][1501],n,cost[1501],h[1501],cnt;
struct edge{int to,nxt;}e[3050];
void add(int u,int v){
    e[++cnt]=edge{v,h[u]};
    h[u]=cnt;
}
void dfs(int x,int p){
    dp[0][x]=cost[x];
    int mn=1e9;
    for(int i=h[x];i;i=e[i].nxt){
        int v=e[i].to;
        if(v==p) continue;
        dfs(v,x);
        dp[0][x]+=min({dp[0][v],dp[1][v],dp[2][v]});
        dp[1][x]+=min(dp[0][v],dp[1][v]);
        dp[2][x]+=min(dp[0][v],dp[1][v]);
        mn=min(mn,dp[0][v]-min(dp[0][v],dp[1][v]));
    }
    dp[1][x]+=mn;
}
signed main(){Aincrad
    cin>>n;
    for(int i=1,k,x,y;i<=n;++i){
        cin>>x>>y>>k;
        cost[x]=y;
        while(k--){
            cin>>y;
            add(x,y);
            add(y,x);
        }
    }
    dfs(1,0);
    cout<<min(dp[0][1],dp[1][1])<<"\n";
    return 0;
}
