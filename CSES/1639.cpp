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
 
int dp[5005][5005];
string a,b;
signed main(){Aincrad
    cin>>a>>b;
    REP1(i,1,a.size()) dp[i][0]=i;
    REP1(i,1,b.size()) dp[0][i]=i;
    REP1(i,1,a.size()) REP1(j,1,b.size())
        dp[i][j]=min({dp[i-1][j-1]+(a[i-1]!=b[j-1]),dp[i-1][j]+1,dp[i][j-1]+1});
    cout<<dp[a.size()][b.size()]<<"\n";
    return 0;
}
