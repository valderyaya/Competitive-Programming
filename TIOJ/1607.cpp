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

long long unsigned int mod=1000000007,dp[1000001]={0,1};
long long unsigned int power(long long unsigned int a,long long unsigned int n){
    long long unsigned int ans=1;
    for(;n;n>>=1,a=a*a%mod) if(n&1) ans=ans*a%mod;
    return ans%mod;
}
long long unsigned int n,m;
int main(){Rosario
    cin>>n;
    REP1(i,2,1000000) dp[i]=dp[i-1]*i%mod;
    while(n--) cin>>m,cout<<dp[m]*power(dp[m>>1]*dp[m/2+1]%mod,mod-2)%mod<<"\n";
//    system("pause");
    return 0;
}
