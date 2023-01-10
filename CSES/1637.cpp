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
 
int dp[1000005],n;
signed main(){Aincrad
    cin>>n;
    dp[0]=0;
    REP1(i,1,9) dp[i]=1;
    REP1(i,10,n) dp[i]=1e9;
    REP1(i,10,n){
        for(int x=i,y;x;x/=10){
            y=x%10;
            if(y) dp[i]=min(dp[i],dp[i-y]+1);
        }
    }
    cout<<dp[n]<<"\n";
    return 0;
}
