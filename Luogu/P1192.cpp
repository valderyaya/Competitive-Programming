//#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#include<bits/stdc++.h>
//#include<bits/extc++.h>
//using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
#define F first
#define S second
#define REP(i,n) for(register int i=0;i<(n);++i)
#define REP1(i,a,b) for(register int i=(a);i<=(b);++i)
#define em emplace_back
#define ALL(x) (x).begin(),(x).end()
#define mkp make_pair
#define pii pair<int,int>
#define pll pair<ll,ll>
#define Rosario ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//#define lb(x) (x&-x)
//#define line cout<<"-------------------------\n";

const int z=100003;
int n,dp[100005],k;
int main(){Rosario
    cin>>n>>k;
    REP1(i,1,k) dp[i]=1;
    for(int i=1;i<=n;++i){
        for(int j=max(0,i-k);j<i;++j) dp[i]=(dp[i]+dp[j])%z;
    }cout<<dp[n]<<"\n";
    return 0;
}
