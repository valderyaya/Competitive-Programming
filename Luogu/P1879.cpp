//#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#include<bits/stdc++.h>
//#include<bits/extc++.h>
//using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
#define F first
#define S second
#define pb push_back
#define REP(i,n) for(int i=0;i<(n);++i)
#define REP1(i,a,b) for(int i=(a);i<=(b);++i)
#define em emplace_back
#define ALL(x) (x).begin(),(x).end()
#define mkp make_pair
#define pii pair<int,int>
#define pll pair<ll,ll>
#define Rosario ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//#define lb(x) (x&-x)

const int mod=1e9;
int n,m,f[5000],dp[13][5000];
bool ck[5000];
int main(){Rosario
    cin>>n>>m; dp[0][0]=1;
    for(int x,i=1;i<=n;++i)
        REP1(j,1,m) cin>>x,f[i]=f[i]<<1|x;
    for(int i=0;i<(1<<m);++i) ck[i]=!(i&(i<<1))&&!(i&(i>>1));
    REP1(i,1,n)
        for(int j=0;j<(1<<m);++j)
            if(ck[j]&&((j&f[i])==j))
                for(int k=0;k<(1<<m);++k)
                    if((j&k)==0) dp[i][j]=(dp[i][j]+dp[i-1][k])%mod;
    int ans=0;
    REP(i,1<<m) ans=(ans+dp[n][i])%mod;
    cout<<ans<<"\n";
    return 0;
}//#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#include<bits/stdc++.h>
//#include<bits/extc++.h>
//using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
#define F first
#define S second
#define pb push_back
#define REP(i,n) for(int i=0;i<(n);++i)
#define REP1(i,a,b) for(int i=(a);i<=(b);++i)
#define em emplace_back
#define ALL(x) (x).begin(),(x).end()
#define mkp make_pair
#define pii pair<int,int>
#define pll pair<ll,ll>
#define Rosario ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//#define lb(x) (x&-x)

const int mod=1e9;
int n,m,f[5000],dp[13][5000];
bool ck[5000];
int main(){Rosario
    cin>>n>>m; dp[0][0]=1;
    for(int x,i=1;i<=n;++i)
        REP1(j,1,m) cin>>x,f[i]=f[i]<<1|x;
    for(int i=0;i<(1<<m);++i) ck[i]=!(i&(i<<1))&&!(i&(i>>1));
    REP1(i,1,n)
        for(int j=0;j<(1<<m);++j)
            if(ck[j]&&((j&f[i])==j))
                for(int k=0;k<(1<<m);++k)
                    if((j&k)==0) dp[i][j]=(dp[i][j]+dp[i-1][k])%mod;
    int ans=0;
    REP(i,1<<m) ans=(ans+dp[n][i])%mod;
    cout<<ans<<"\n";
    return 0;
}
