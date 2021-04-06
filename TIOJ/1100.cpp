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

int n,dp[10000005],mx;
int main(){Rosario
    while(cin>>n,n){
        dp[0]=mx=0; int r,d,p;
        REP(i,n){
            cin>>r>>d>>p;
            if(d>mx){
                for(int j=mx+1;j<=d;++j) dp[j]=dp[mx];
                mx=d;
            }
            for(int j=d;j>=r+p-1;--j)
                if(dp[j-p]+1>dp[j]) dp[j]=dp[j-p]+1;
        }
        cout<<dp[mx]<<"\n";
    }
    return 0;
}
