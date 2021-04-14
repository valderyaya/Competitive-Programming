#include<bits/stdc++.h>
// #include<ext/rope>
// using namespace __gnu_cxx;
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define REP1(i,a,b) for(int i=(a);i<=(b);i++)
#define pii pair<int,int>
typedef long long ll;
#define mkp make_pair
#define em emplace_back
#define F first
#define S second
#define ALL(x) (x).begin(),(x).end()
#define Rosario ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define pll pair<ll,ll>
#define lb(x) (x&-x)

ll n,dp[105][105];
int main(){Rosario
    while(cin>>n){
    memset(dp,0,sizeof(dp));
    REP1(i,1,n) cin>>dp[i][i];
    for(int j=2;j<=n;j++)
        for(int i=j-1;i>0;i--)
            for(int k=i;k<j;k++) dp[i][j]=max(dp[i][j],(j-i+1)&1?dp[i][k]*dp[k+1][j]:dp[i][k]+dp[k+1][j]);
    cout<<dp[1][n]<<"\n";
    }
//    system("pause");
    return 0;
}

