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

const int inf=1e8;
int dp[105][105],a[105][105],n;
int main(){Rosario
    while(cin>>n){int ans=0;
        REP1(i,0,100) REP1(j,0,100) dp[i][j]=inf;
        REP1(i,1,n) REP1(j,1,i) cin>>a[i][j],dp[i][j]=0;
        //REP1(i,1,n) dp[i][0]=dp[i][i+1]=inf;
        dp[1][1]=a[1][1];
        REP1(i,2,n) REP1(j,1,i) {
            int mx=min(dp[i-1][j],dp[i-1][j-1]);
            if(mx>=a[i][j]) dp[i][j]=mx+1;
            else dp[i][j]=a[i][j]+1;
            ans=max(ans,dp[i][j]);
        }
        cout<<ans<<"\n";
    }
    return 0;
}
