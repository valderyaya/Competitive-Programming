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

const int inf=1e9;
int n,m,dp[55005],c,w;
int main(){Rosario
    cin>>n>>m;
    fill(dp+1,dp+m+5000,inf);
    REP(i,n){
        cin>>w>>c;
        for(int j=w;j<=m+5000;++j) dp[j]=min(dp[j],dp[j-w]+c);
    }
    cout<<*min_element(dp+m,dp+m+5000)<<"\n";
    return 0;
}
