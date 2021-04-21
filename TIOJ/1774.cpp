//#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#include<bits/stdc++.h>
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
#define lb(x) (x&-x)

ll n,m,dp[2005];
pll a[2005];
int main(){Rosario
    cin>>n>>m;
    REP(i,n) cin>>a[i].F>>a[i].S;
    REP(i,n)
        for(int j=a[i].S;j<=m;j++) dp[j]=max(dp[j],dp[j-a[i].S]+a[i].F);
    cout<<dp[m]<<"\n";
//    system("pause");
    return 0;
}
