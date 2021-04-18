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

#define int ll
int dp[2][5005],n,m,now,sum=0,mx=0;
string s;
main(){//Rosario
    cin>>n>>m;
    REP1(i,1,n){cin>>s;
        REP1(j,1,m){dp[now][j]=0;
            if(s[j-1]=='0'){
                mx=max(mx,dp[now][j]=min({dp[now^1][j],dp[now][j-1],dp[now^1][j-1]})+1);
                sum+=dp[now][j];
            }
        }now^=1;
    }
    cout<<sum<<' '<<mx<<"\n";
    return 0;
}
