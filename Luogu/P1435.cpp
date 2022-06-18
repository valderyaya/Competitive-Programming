//#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#include<bits/stdc++.h>
//#include<bits/extc++.h>
//using namespace __gnu_pbds;
using namespace std;
#define F first
#define S second
typedef long long ll;
#define REP(i,n) for(register int i=0;i<(n);++i)
#define REP1(i,a,b) for(register int i=(a);i<=(b);++i)
#define em emplace_back
#define mkp make_pair
#define pb push_back
#define ALL(x) (x).begin(),(x).end()
#define pii pair<int,int>
#define pll pair<ll,ll>
#define Alicization ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define lb(x) (x&-x)
 
string s,r;
int dp[2][1005],now;
signed main(){Alicization
    cin>>s;
    r=s;
    reverse(ALL(r));
    REP1(i,1,s.size()) {
        REP1(j,1,r.size())
            if(s[i-1]==r[j-1]) dp[now][j]=dp[now^1][j-1]+1;
            else dp[now][j]=max(dp[now][j-1],dp[now^1][j]);
        now^=1;
    }
    cout<<int(s.size())-dp[now^1][s.size()]<<"\n";
    return 0;
}
