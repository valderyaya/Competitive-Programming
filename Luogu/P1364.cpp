#include<bits/stdc++.h>
//#include<bits/extc++.h>
//using namespace __gnu_pbds;
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
#define Rosario ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define pll pair<ll,ll>
//#define lb(x) (x&-x)

int n,dp[101][101],sum,mi=1e9,a[101];
int main(){Rosario
    cin>>n;
    int x,y;
    REP1(i,1,n) REP1(j,1,n) dp[i][j]=1e9;
    REP1(i,1,n) {
        dp[i][i]=0;
        cin>>a[i]>>x>>y;
        if(x) dp[x][i]=dp[i][x]=1;
        if(y) dp[y][i]=dp[i][y]=1;
    }
    REP1(k,1,n) REP1(i,1,n) REP1(j,1,n) dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
    REP1(i,1,n){
        sum=0;
        REP1(j,1,n) sum+=dp[i][j]*a[j];
        mi=min(mi,sum);
    }cout<<mi<<"\n";
//    system("pause");
    return 0;
}
