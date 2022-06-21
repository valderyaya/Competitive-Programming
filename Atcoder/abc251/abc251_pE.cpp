#include<bits/stdc++.h>
using namespace std;
#define valder ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define ll long long
#define F first
#define S second
#define ALL(x) x.begin(),x.end()
#define pii pair<int,int>
#define REP(i,n) for(int i=0;i<n;++i)
#define REP1(i,a,b) for(int i=a;i<=b;++i)
#define em emplace_back
#define lb(x) x&-x
#define pll pair<ll,ll>
#define mkp make_pair

ll n,dp[300005],a[300005],ans;
signed main(){valder
    cin>>n;
    REP1(i,1,n) cin>>a[i];
    dp[1]=dp[2]=a[1];
    REP1(i,3,n) dp[i]=min(dp[i-2]+a[i-1],dp[i-1]+a[i]);
    ans=dp[n], dp[0]=dp[1]=a[n];
    REP1(i,2,n-1) dp[i]=min(dp[i-2]+a[i-1],dp[i-1]+a[i]);
    cout<<min(ans,dp[n-1])<<"\n";
    return 0;
}
