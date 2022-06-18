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
#define Alicization ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define lb(x) (x&-x)
 
int dp[105][105],n,k;
pii a[105];
signed main(){Alicization
    cin>>n>>k;
    REP1(i,1,n) cin>>a[i].F>>a[i].S;
    sort(a+1,a+1+n);
    REP1(i,2,n)
        REP1(j,2,min(i,n-k)){
            dp[i][j]=0x3f3f3f;
            REP1(k,j-1,i-1) dp[i][j]=min(dp[i][j],dp[k][j-1]+abs(a[k].S-a[i].S));
    }
    int mn=0x3f3f3f;
    REP1(i,n-k,n) mn=min(mn,dp[i][n-k]);
    cout<<mn<<"\n";
    return 0;
}
