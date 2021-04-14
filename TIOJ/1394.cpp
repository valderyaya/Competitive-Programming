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
#define pii pair<int,int>
#define pll pair<ll,ll>
#define Rosario ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//#define lb(x) (x&-x)

int n,dp[2][33000],m;
vector<int> v[33000];
void dfs(int x){
    dp[0][x]=0,dp[1][x]=1;
    for(auto &i:v[x]){
        dfs(i);
        dp[0][x]+=dp[1][i];
        dp[1][x]+=min(dp[0][i],dp[1][i]);
    }
}
int main(){Rosario
    cin>>n; int x;
    REP(i,n){
        cin>>m;
        while(m--) cin>>x,v[i].em(x);
    }
    dfs(0);
    cout<<min(dp[0][0],dp[1][0])<<"\n";
    return 0;
}
