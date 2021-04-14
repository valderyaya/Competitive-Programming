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
int dp[33000],n,a[33000];
 main(){Rosario
    while(cin>>a[1]){
        dp[0]=0;dp[1]=a[n=1];
        if(a[1]){
            for(n=2;;++n){
                cin>>a[n]; dp[n]=1e9;
                for(int i=n-1;i>=0&&i>=n-3;--i) dp[n]=min(dp[n],dp[i]);
                dp[n]+=a[n];
                if(a[n]==0) break;
            }
        }
        cout<<(10*(dp[n]+n*10))<<"\n";
    }
    return 0;
}
