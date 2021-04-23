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

pii a[1005];
int t,n,b,w,dp[10005],m;
int main(){Rosario
    cin>>t;
    while(t--){
        cin>>w>>b>>n;
        memset(dp,0,sizeof(dp));
        REP(i,n) cin>>a[i].F>>a[i].S;
        cin>>m;
        REP(i,n){
            a[i].F+=m;
            for(int j=a[i].F;j<w;++j) dp[j]=max(dp[j],dp[j-a[i].F]+a[i].S);
        }cout<<(dp[w-1]>=b?"Yes":"No")<<"\n";
    }
    return 0;
}
