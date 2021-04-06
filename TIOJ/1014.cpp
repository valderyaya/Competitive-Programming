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

const int z=16;
int dp[z][1<<z],n,a[z];
int main(){Rosario
    cin>>n;
    REP(i,n) cin>>a[i];
    memset(dp,0x7f,sizeof(dp));
    dp[0][0]=1;
    for(int i=1;i<(1<<n);++i)
        for(int j=0;j<n;++j)
            if(i>>j&1)
                for(int k=0,x;k<n;++k){
                    x=dp[k][i-(1<<j)]+abs(j-k);
                    dp[j][i]=min(dp[j][i],((x-1)/a[j]+1)*a[j]);
                }
    int ans=1e9;
    REP(i,n) ans=min(ans,dp[i][(1<<n)-1]);
    cout<<ans<<"\n";
    return 0;
}
