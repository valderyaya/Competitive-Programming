#include<bits/stdc++.h>
#include<bits/extc++.h>
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
int n,m,dp[1001]={},lose[1001],win[1001],c[1001];
main(){Rosario
    cin>>n>>m;
    REP(i,n) cin>>lose[i]>>win[i]>>c[i];
    REP(i,n){
        for(int j=m;j>=c[i];j--) dp[j]=max(dp[j]+lose[i],dp[j-c[i]]+win[i]);
        for(int j=c[i]-1;j>=0;j--) dp[j]+=lose[i];
    }cout<<dp[m]*5<<"\n";
//    system("pause");
}
