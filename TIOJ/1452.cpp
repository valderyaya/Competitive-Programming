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

ll dp[15][1<<15];
int n,m;
ll dfs(int i,int x,int s,int now){
    if(x==m) return dp[i-1][now];
    if(!(s&(1<<x))) return dfs(i,x+1,s,now);
    ll ret=dfs(i,x+1,s,now^(1<<x));
    if(s&(1<<(x+1))) ret+=dfs(i,x+2,s,now);
    return ret;
}
signed main(){Aincrad
    while(cin>>n>>m,n+m){
        memset(dp,0,sizeof(dp));
        dp[0][(1<<m)-1]=1;
        REP1(i,1,n) REP(j,1<<m) dp[i][j]=dfs(i,0,j,(1<<m)-1);
        cout<<dp[n][(1<<m)-1]<<"\n";
    }
    return 0;
}
