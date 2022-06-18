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

int q,n,m,dp[201][201],d[201];
void floyd(int k){
    REP(i,n) REP(j,n) dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
}
int main(){Rosario
    cin>>n>>m;
    REP(i,n) REP(j,n) dp[i][j]=1e9;
    REP(i,n) cin>>d[i],dp[i][i]=0;
    int now=0,a,b,c;
    REP(i,m) cin>>a>>b>>c,dp[a][b]=dp[b][a]=c;
    cin>>q;
    REP(i,q){
        cin>>a>>b>>c;
        while(d[now]<=c&&now<n) floyd(now++);
        if(d[a]>c||d[b]>c||dp[a][b]==1e9) cout<<"-1\n";
        else cout<<dp[a][b]<<"\n";
    }
//    system("pause");
    return 0;
}
