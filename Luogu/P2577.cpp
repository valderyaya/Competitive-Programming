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

const int z=205;
int n,dp[z][z*z],sum[z];
struct qq{
    int a,b;
    bool operator<(const qq &x)const{return b>x.b;}
}qwq[z];
int main(){Rosario
    cin>>n;
    REP1(i,1,n) cin>>qwq[i].a>>qwq[i].b;
    sort(qwq+1,qwq+1+n);
    REP1(i,1,n) sum[i]=sum[i-1]+qwq[i].a;
    memset(dp,127,sizeof(dp));
    dp[0][0]=0;
    REP1(i,1,n)
        REP1(j,0,sum[i]){
            if(j>=qwq[i].a) dp[i][j]=min(dp[i][j],max(dp[i-1][j-qwq[i].a],j+qwq[i].b));
            dp[i][j]=min(dp[i][j],max(dp[i-1][j],sum[i]-j+qwq[i].b));
        }
    int ans=2147483647;
    REP1(i,0,sum[n]) ans=min(ans,dp[n][i]);
    cout<<ans<<"\n";
    return 0;
}
