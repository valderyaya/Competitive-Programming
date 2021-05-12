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


int dp[11][11],a[11][11],n;
int main(){Rosario
    cin>>n;
    for(int x,y,c;;){
        cin>>x>>y>>c;
        if(!x) break;
        a[x][y]=c;
    }
    REP1(p,2,n<<1) for(int i=p-1;i;--i) for(int j=p-1;j;--j){
        int k=p-i,l=p-j;
        dp[i][j]=max({dp[i][j],dp[i-1][j-1],dp[i-1][j],dp[i][j-1]})+a[i][k];
        if(i!=j) dp[i][j]+=a[j][l];
    }
    cout<<dp[n][n]<<"\n";
    return 0;
}
