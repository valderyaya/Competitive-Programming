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
#define Rosario ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//#define lb(x) (x&-x)

const int z=1<<21;
int n,t,dp[z],a[22][22];
int main(){Rosario
    cin>>t;
    while(t--){
        cin>>n;
        REP(i,n) REP(j,n) cin>>a[i][j];
        fill(dp,dp+z,z); dp[0]=0;
        REP(i,1<<n)
            if(dp[i]<z){
                int j=__builtin_ctz(~i);
                for(int k=j+1;k<n;++k)
                    if(!(i>>k&1))
                        for(int l=k+1;l<n;++l)
                            if(!(i>>l&1)){
                                int p=1<<j|1<<k|1<<l;
                                dp[p|i]=min(dp[p|i],dp[i]+a[j][k]+a[k][l]+a[l][j]);
                            }
            }
        cout<<dp[(1<<n)-1]<<"\n";
    }
    return 0;
}
