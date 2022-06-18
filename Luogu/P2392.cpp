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

int a[4],b[20],dp[1500],n,sum;
int main(){Rosario
    REP(i,4) cin>>a[i];
    REP(o,4){
        n=0;
        REP(i,a[o]) cin>>b[i],n+=b[i];
        REP(i,a[o])
            for(int j=n>>1;j>=b[i];j--) dp[j]=max(dp[j],dp[j-b[i]]+b[i]);
        sum+=n-dp[n>>1];
        memset(dp,0,sizeof(dp));
    }cout<<sum<<"\n";
    return 0;
}
