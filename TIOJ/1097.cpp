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

int n,m,dp[2][5005],mx,now;
int main(){Rosario
    while(cin>>n>>m,n||m){mx=now=0;
        REP1(i,1,m) dp[0][i]=dp[1][i]=0;
        REP1(i,1,n) {
            REP1(j,1,m){
                cin>>dp[now][j]; dp[now][j]= dp[now][j]==2?0:1;
                if(dp[now][j]) mx=max(mx,dp[now][j]=min({dp[now][j-1],dp[now^1][j],dp[now^1][j-1]})+1);
            }now^=1;
        }cout<<mx*mx<<"\n";
    }
    return 0;
}
