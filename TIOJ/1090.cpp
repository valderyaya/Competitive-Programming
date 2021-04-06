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

#define int ll
int dp[2][1005][1005],n,m,a[1005];
main(){Rosario
    cin>>n>>m;
    REP1(i,1,n) cin>>a[i];
    a[++n]=m; sort(a+1,a+1+n);
    REP1(i,0,n) REP1(j,0,n) dp[0][i][j]=dp[1][i][j]=1e9;
    int p=lower_bound(a+1,a+1+n,m)-a; dp[0][p][p]=dp[1][p][p]=0;
    for(int i=p;i;--i) for(int j=p;j<=n;++j){ int t=n-j+i;
        if(i==j) continue;
        dp[0][i][j]=min({dp[0][i][j],dp[0][i+1][j]+(a[i+1]-a[i])*t,dp[1][i+1][j]+(a[j]-a[i])*t});
        dp[1][i][j]=min({dp[1][i][j],dp[1][i][j-1]+(a[j]-a[j-1])*t,dp[0][i][j-1]+(a[j]-a[i])*t});
    }
    cout<<min(dp[0][1][n],dp[1][1][n])<<"\n";
    return 0;
}
