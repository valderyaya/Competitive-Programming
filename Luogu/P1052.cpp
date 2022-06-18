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
#define lb(x) (x&-x)
 
int dp[10500],a[105],b[105],s,t,n,m;
bool vis[10500];
signed main(){Rosario
    cin>>n>>s>>t>>m;
    int lc=s*t,ans=1e9;
    REP1(i,1,m) cin>>a[i];
    if(s==t){
        int cnt=0;
        REP1(i,1,m) cnt+=(a[i]%t==0);
        return cout<<cnt,0;
    }
    sort(a+1,a+1+m);
    REP1(i,1,m){
        int d=a[i]-a[i-1];
        d=min(d,lc);
        b[i]=b[i-1]+d;
        vis[b[i]]=1;
    }
    memset(dp,0x3f3f,sizeof(dp));
    n=b[m]+lc;
    dp[0]=0;
    REP1(i,1,n)
        REP1(j,s,t)
            if(i-j>=0) dp[i]=min(dp[i],dp[i-j]+vis[i]);
    REP1(i,b[m],n) ans=min(ans,dp[i]);
    cout<<ans<<"\n";
    return 0;
}
