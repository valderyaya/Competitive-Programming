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
#define ALL(x) (x).begin(),(x).end()
#define pii pair<int,int>
#define pll pair<ll,ll>
#define Rosario ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//#define lb(x) (x&-x)

int x,n,m,dp[45005]={};
int main(){Rosario
	cin>>n>>m;
    REP1(i,1,m){
        cin>>x;
        for(int j=n;j>=x;--j) dp[j]=max(dp[j],dp[j-x]+x);
    }cout<<dp[n]<<"\n";
	return 0;
}
