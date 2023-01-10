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
 
ll n,ans,m,dp[105][100001],x;
const ll md=1e9+7;
signed main(){Aincrad
    cin>>n>>m>>x;
    if(!x) REP1(i,1,m) dp[i][1]=1;
    else dp[x][1]=1;
    REP1(i,2,n){
        cin>>x;
        if(x) dp[x][i]=((dp[x][i-1]+dp[x-1][i-1])%md+dp[x+1][i-1])%md;
        else REP1(j,1,m) dp[j][i]=((dp[j][i-1]+dp[j-1][i-1])%md+dp[j+1][i-1])%md;
    }
    REP1(i,1,m) ans=(ans+dp[i][n])%md;
    cout<<ans<<"\n";
    return 0;
}
