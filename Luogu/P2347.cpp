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

int dp[1005]={1},a[6],w[]={1,2,3,5,10,20};
int main(){Rosario
    REP(i,6) cin>>a[i];
    REP(i,6)
        while(a[i]--)
            for(int j=1000;j>=w[i];--j) dp[j]+=dp[j-w[i]];
    int cnt=0;
    REP1(i,1,1000) if(dp[i]) ++cnt;
    cout<<"Total="<<cnt<<"\n";
    return 0;
}
