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

int dp[10005]={},n,m,k;
int main(){Rosario
    cin>>n>>m>>k;
    int x,y;
    while(m--){
        cin>>x>>y;
        for(int i=k;i>=y;--i) dp[i]=max(dp[i],dp[i-y]+x);
    }
    REP1(i,1,k) if(dp[i]>=n) return cout<<k-i<<"\n",0;
    cout<<"Impossible";
    return 0;
}
