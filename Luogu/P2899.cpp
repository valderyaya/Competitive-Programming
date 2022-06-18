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

int dp[3][10001],n;
vector<int> v[10001];
void dfs(int x,int p){
    dp[0][x]=1;
    int mn=1e9;
    for(int i:v[x]){
        if(i==p) continue;
        dfs(i,x);
        dp[0][x]+=min({dp[0][i],dp[1][i],dp[2][i]});
        dp[1][x]+=min(dp[0][i],dp[1][i]);
        dp[2][x]+=min(dp[0][i],dp[1][i]);
        mn=min(mn,dp[0][i]-min(dp[0][i],dp[1][i]));
    }
    dp[1][x]+=mn;
}
signed main(){Aincrad
    cin>>n;
    for(int i=1,x,y;i<n;++i){
        cin>>x>>y;
        v[x].em(y);
        v[y].em(x);
    }
    dfs(1,0);
    cout<<min({dp[0][1],dp[1][1]})<<"\n";
    return 0;
}
