#include<bits/stdc++.h>
// #include<ext/rope>
// using namespace __gnu_cxx;
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define REP1(i,a,b) for(int i=(a);i<=(b);i++)
#define pii pair<int,int>
typedef long long ll;
#define mkp make_pair
#define em emplace_back
#define F first
#define S second
#define ALL(x) (x).begin(),(x).end()
#define oi ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define pll pair<ll,ll>
//#define lb(x) (x&-x)

int n,m,dp[10005];
pii a[10005];
int main(){
    oi;
    cin>>n>>m;
    REP(i,m) cin>>a[i].F>>a[i].S;
    REP(i,m){
        for(int j=a[i].S;j<=n;j++) dp[j]=max(dp[j],dp[j-a[i].S]+a[i].F);
    }
    cout<<dp[n]<<"\n";
//    system("pause");
    return 0;
}
