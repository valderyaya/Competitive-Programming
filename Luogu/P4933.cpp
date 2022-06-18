//#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#include<bits/stdc++.h>
//#include<bits/extc++.h>
//using namespace __gnu_pbds;
using namespace std;
#define F first
#define S second
typedef long long ll;
#define REP(i,n) for(int i=0;i<(n);++i)
#define REP1(i,a,b) for(int i=(a);i<=(b);++i)
#define em emplace_back
#define mkp make_pair
#define pii pair<int,int>
#define pll pair<ll,ll>
#define Rosario ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//#define lb(x) (x&-x)

const ll mod=998244353,N=20001;
ll n,a[1005],dp[1002][N*2+10]={},ans=0;
int main(){Rosario
    cin>>n;
    REP1(i,1,n) cin>>a[i];
    REP1(i,2,n)
        for(int j=1;j<i;++j){
            dp[i][a[i]-a[j]+N]=(dp[i][a[i]-a[j]+N]+dp[j][a[i]-a[j]+N]+1)%mod;
            ans=(ans+dp[j][a[i]-a[j]+N]+1)%mod;
        }
    cout<<(ans+n)%mod<<"\n";
    return 0;
}
