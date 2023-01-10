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
 
const ll md=1e9+7;
ll dp[1000005],n,m,x;
signed main(){Aincrad
    dp[0]=1;
    cin>>n>>m;
    REP1(i,1,n){
        cin>>x;
        for(int j=0;j+x<=m;++j) dp[j+x]=(dp[j+x]+dp[j])%md;
    }
    cout<<dp[m]<<"\n"; 
    return 0;
}
