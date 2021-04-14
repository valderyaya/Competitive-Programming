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
#define wait system("pause");

int dp[1002][1002];
string a,b;
int main(){Rosario
    getline(cin,a);
    getline(cin,b);
    REP1(i,0,a.size()) dp[i][0]=i;
    REP1(i,0,b.size()) dp[0][i]=i;
    REP1(i,1,a.size())
        REP1(j,1,b.size())
            if(a[i-1]==b[j-1]) dp[i][j]=dp[i-1][j-1];
            else dp[i][j]=min({dp[i-1][j],dp[i][j-1],dp[i-1][j-1]})+1;
    cout<<dp[a.size()][b.size()]<<"\n";
//    system("pause");
    return 0;
}
