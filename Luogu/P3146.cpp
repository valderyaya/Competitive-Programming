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

int dp[250][250],n,ans=0;
int main(){Rosario
    cin>>n;
    REP1(i,1,n) cin>>dp[i][i];
    REP1(l,2,n)
        for(int j,k,i=1;i+l-1<=n;++i)
            for(j=i+l-1,k=i;k<j;++k)
                if(dp[i][k]==dp[k+1][j]&&dp[i][k]&&dp[k+1][j]){
                    dp[i][j]=max(dp[i][j],dp[i][k]+1);
                    ans=max(ans,dp[i][j]);
                }
    cout<<ans<<"\n";
    return 0;
}
