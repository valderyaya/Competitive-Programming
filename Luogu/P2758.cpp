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

string a,b;
int dp[2005][2005];
int main(){Rosario
    cin>>a>>b;
    REP1(i,0,a.size()) dp[i][0]=i;
    REP1(i,0,b.size()) dp[0][i]=i;
    REP(i,a.size()) REP(j,b.size()) 
        dp[i+1][j+1]=(a[i]==b[j]?min({dp[i][j],dp[i][j+1]+1,dp[i+1][j]+1}):min({dp[i][j+1],dp[i+1][j],dp[i][j]})+1);
    cout<<dp[a.size()][b.size()]<<"\n";
//    system("pause");
    return 0;
}
