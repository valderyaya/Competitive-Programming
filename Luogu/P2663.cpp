#include<bits/stdc++.h>
//#include<bits/extc++.h>
//using namespace __gnu_pbds;
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define REP1(i,a,b) for(int i=(a);i<=(b);i++)
#define pii pair<int,int>
typedef long long ll;
#define mkp make_pair
#define em emplace_back
#define F first
#define S second
#define ALL(x) (x).begin(),(x).end()
#define Rosario ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define pll pair<ll,ll>
//#define lb(x) (x&-x)

int n,a[101],dp[10005],sum=0;
int main(){Rosario
    cin>>n;
    REP(i,n) cin>>a[i],sum+=a[i];
    sum>>=1;
    REP(i,n) for(int j=sum;j>=a[i];j--) dp[j]=max(dp[j],dp[j-a[i]]+a[i]);
    cout<<dp[sum]<<"\n";
//    system("pause");
    return 0;
}
