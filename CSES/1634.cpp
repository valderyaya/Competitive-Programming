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
 
int dp[1000005],n,m,a[101];
signed main(){Aincrad
    dp[0]=0;
    cin>>n>>m;
    REP1(i,1,n) cin>>a[i];
    REP1(i,1,m){
        dp[i]=1e9;
        REP1(j,1,n) if(i-a[j]>=0&&dp[i-a[j]]!=1e9) dp[i]=min(dp[i],dp[i-a[j]]+1);
    } 
    //REP1(i,1,m) cout<<dp[i]<<" \n"[i==m];
    cout<<(dp[m]==1e9?-1:dp[m])<<"\n"; 
    return 0;
}
