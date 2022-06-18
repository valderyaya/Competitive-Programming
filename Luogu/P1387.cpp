#include<bits/stdc++.h>
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

int a[101][101],dp[101][101]={},m,n,mx=0;
int main(){Rosario
    cin>>n>>m;
    REP1(i,1,n) REP1(j,1,m) cin>>a[i][j];
    REP1(i,1,n) REP1(j,1,m){
        if(a[i][j]==1) dp[i][j]=min({dp[i-1][j],dp[i][j-1],dp[i-1][j-1]})+1,mx=max(mx,dp[i][j]);
    }
    cout<<mx<<"\n";
//    system("pause");
    return 0;
}
