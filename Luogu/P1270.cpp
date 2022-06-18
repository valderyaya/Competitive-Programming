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

int tim,dp[1001][1001];
pii a[10001];
void read(int x){
    cin>>a[x].F>>a[x].S;
    a[x].F<<=1;
    if(!a[x].S) read(x<<1),read(x<<1|1);
}
int dfs(int x,int re){
    if(dp[x][re]||re<=0) return dp[x][re];
    if(a[x].S) return dp[x][re]=min(a[x].S,(re-a[x].F)/5);
    REP1(i,0,re-a[x].F)
        dp[x][re]=max(dp[x][re],dfs(x<<1,i)+dfs(x<<1|1,re-a[x].F-i));
    return dp[x][re];
}
int main(){Rosario
    cin>>tim;
    read(1);
    cout<<dfs(1,tim-1)<<"\n";
    return 0;
}
