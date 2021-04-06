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



bool dp[2][101][101];
int mol(int x,int mod){
    if(x>=0) return x%mod;
    return x%mod+mod;
}
int main(){Rosario
    int n,m,k,x1,x2,y1,y2;
    cin>>n>>m>>x1>>y1>>x2>>y2>>k;
    int x; dp[0][x1][y1]=1;
    REP1(i,1,k){
        cin>>x; int c=i&1;
        REP(i,n) 
          REP(j,m) 
            dp[c][i][j]=dp[c^1][i][mol(j+x,m)]|dp[c^1][i][mol(j-x,m)]|dp[c^1][mol(i-x,n)][j]|dp[c^1][mol(i+x,n)][j];
    }
    cout<<(dp[k&1][x2][y2]?"YES":"NO")<<"\n"; 
    return 0;
}
