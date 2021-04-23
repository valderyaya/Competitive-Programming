//#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
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

const int inf=1e9;
int t,dp[202][202],a[202],n,m;
int main(){Rosario
    cin>>t;
    while(t--){
        cin>>n>>m;
        REP1(i,1,n) cin>>a[i],dp[i][i]=1;
        REP1(i,1,n) for(int j=i-1;j>0;--j){
            dp[j][i]=inf;
            for(int k=j;k<i;++k) dp[j][i]=min(dp[j][i],dp[j][k]+dp[k+1][i]);
            dp[j][i]-=(a[i]==a[j]?1:0);
        }
        cout<<dp[1][n]<<"\n";
    }
    return 0;
}
