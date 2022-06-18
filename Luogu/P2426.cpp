#include<bits/stdc++.h>
//#include<bits/extc++.h>
//using namespace __gnu_pbds;
using namespace std;
#define F first
#define S second
typedef long long ll;
#define REP(i,n) for(int i=0;i<(n);++i)
#define REP1(i,a,b) for(int i=(a);i<=(b);++i)
#define em emplace_back
#define mkp make_pair
#define pii pair<int,int>
#define pll pair<ll,ll>
#define Rosario ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//#define lb(x) (x&-x)

int n,dp[105],a[105];
int main(){Rosario
    cin>>n;
    REP1(i,1,n) cin>>a[i];
    REP1(i,1,n){
        dp[i]=max(dp[i],dp[i-1]+a[i]);
        for(int j=2;j<=i;++j) dp[i]=max(dp[i],dp[i-j]+abs(a[i]-a[i-j+1])*j);
    }cout<<dp[n]<<"\n";
    return 0;
}
