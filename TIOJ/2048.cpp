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


const ll inf=1LL<<60;
const int N=1e6+1;
ll a[N],mx[N],dp[N],sum,n,m=-inf;
int main(){Rosario
    cin>>n;
    REP1(i,1,n) cin>>a[i];
    REP1(i,1,n){
        sum+=a[i]; m=max(m,sum);
        if(sum<0) sum=0;
        mx[i]=m;
    }
    dp[1]=dp[2]=-inf; m=-inf;
    REP1(i,3,n) dp[i]=max(m,mx[i-2])+a[i],m=max(m,dp[i]);
    cout<<*max_element(dp+1,dp+1+n)<<"\n";
//    system("pause");
    return 0;
}
