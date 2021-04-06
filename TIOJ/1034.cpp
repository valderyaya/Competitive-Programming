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

const int z=405,inf=1e9;
int n,dp[z][z],a[z];
int h(int x,int y){return x*n+y;}
int main(){Rosario
    while(cin>>n){
        REP(i,z) REP(j,z) dp[i][j]=(i==j?0:inf);
        REP(i,n) REP(j,n){cin>>a[h(i,j)];
            if(i) dp[h(i,j)][h(i-1,j)]=a[h(i-1,j)],dp[h(i-1,j)][h(i,j)]=a[h(i,j)];
            if(j) dp[h(i,j)][h(i,j-1)]=a[h(i,j-1)],dp[h(i,j-1)][h(i,j)]=a[h(i,j)];
        }
        REP(k,n*n) REP(i,n*n) REP(j,n*n) dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
        int sx,sy,ex,ey,m;
        cin>>m;
        while(m--){
            cin>>sx>>sy>>ex>>ey;
            int mn=inf; --sx,--sy,--ex,--ey;
            REP(i,n*n) mn=min(mn,a[h(sx,sy)]+dp[h(sx,sy)][i]+dp[i][h(ex,ey)]-a[i]);
            cout<<mn<<"\n";
        }
    }
    return 0;
}
