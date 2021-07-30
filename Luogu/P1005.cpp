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

__int128_t power(__int128_t a,__int128_t n){
    __int128_t res=1;
    for(;n;n>>=1,a*=a) if(n&1) res*=a;
    return res;
}
int n,m,a[85][85];
__int128_t ans=0,dp[85][85];
void print(__int128_t x){
    if(!x) return;
    print(x/10);
    putchar(x%10+'0');
}
int main(){//Rosario
    cin>>n>>m;
    REP1(i,1,n) REP1(j,1,m) cin>>a[i][j];
    REP1(i,1,n){
        REP1(j,1,m) dp[j][j]=a[i][j]*power(__int128_t(2),m);
        REP1(l,2,m)
            for(int j=1,k=j+l-1;k<=m;++j,++k){
                dp[j][k]=max(dp[j+1][k]+a[i][j]*power(__int128_t(2),m-l+1),dp[j][k-1]+a[i][k]*power(__int128_t(2),m-l+1));
                //cout<<j<<' '<<k<<' '<<dp[j][k]<<endl;
            }
        //cout<<dp[1][m]<<"\n";
        ans+=dp[1][m];
    }
    if(ans)  print(ans);
    else puts("0");
    return 0;
}
