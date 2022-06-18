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

int n,dp[3000005],mx=0;
vector<int> v[3000001];
int main(){Rosario
    cin>>n;
    int x,y;
    REP(i,n){
        cin>>x>>y;
        v[y].em(x-1);
        mx=max(mx,y);
    }
    REP1(i,1,mx){
        dp[i]=dp[i-1];
        for(auto &j:v[i]) dp[i]=max(dp[i],dp[j]+i-j);
    }cout<<dp[mx]<<"\n";
    return 0;
}
