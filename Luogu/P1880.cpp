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

int dp[2][205][205],n,sum[205],a[205];
int s(int l,int r){return sum[r]-sum[l-1];}
int main(){Rosario
    cin>>n;
    REP1(i,1,n) cin>>a[i],a[i+n]=a[i],sum[i]=sum[i-1]+a[i];
    for(int i=n+1;i<=n+n;i++) sum[i]=sum[i-1]+a[i];
    for(int k=2;k<=n;k++)
        for(int l=1,r=l+k-1;r<=n+n;r++,l++){
            dp[1][l][r]=1e9;
            for(int i=l;i<r;i++){
                dp[0][l][r]=max(dp[0][l][r],dp[0][l][i]+dp[0][i+1][r]+s(l,r));
                dp[1][l][r]=min(dp[1][l][r],dp[1][l][i]+dp[1][i+1][r]+s(l,r));
            }
        }
    int mx,mn=1e9;
    for(int i=1;i<=n;i++) mx=max(mx,dp[0][i][i+n-1]),mn=min(mn,dp[1][i][i+n-1]);
    cout<<mn<<'\n'<<mx;
    return 0;
}
