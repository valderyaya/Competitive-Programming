#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define F first
#define S second
#define REP(i,n) for(int i=0;i<(n);i++)
#define REP1(i,a,b) for(int i=(a);i<=(b);i++)
#define em emplace_back
#define ALL(x) (x).begin(),(x).end()
#define mkp make_pair
#define pii pair<int,int>
#define pll pair<ll,ll>
#define Rosario ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define lb(x) (x&-x)


ll n,m,dp[1000][4]={};
int main(){//Rosario
    cin>>n;dp[1][1]=dp[1][2]=dp[1][3]=1;int i=2;
    while(n--){cin>>m;
        if(dp[m][0]){cout<<dp[m][0]<<"\n";continue;}
        for(;i<=m;i++){
            dp[i][0]=dp[i-1][1]+dp[i-1][2]+dp[i-1][3];
            dp[i][1]=dp[i-1][0]+dp[i-1][2]+dp[i-1][3];
            dp[i][2]=dp[i-1][1]+dp[i-1][0]+dp[i-1][3];
            dp[i][3]=dp[i-1][1]+dp[i-1][2]+dp[i-1][0];
        }
        cout<<dp[m][0]<<"\n";
    }
//    system("pause");
    return 0;
}
