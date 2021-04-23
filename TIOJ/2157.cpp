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
const int mod=998244353;
int n,a[500005],now,p[500005]={1};
ll sum=0;
main(){Rosario
    cin>>n;
    for(int i=1;i<=n;++i) p[i]=p[i-1]*2%mod;
    REP(i,n) cin>>a[i];
    sort(a,a+n);
    for(int j,i=n-1;i>=0;--i){
        sum=(sum+p[i]*a[i])%mod;
        // for(j=i;j>=0&&a[j]==a[i];--j) sum=(sum+p[i]*a[i])%mod;
        // i=j;
    }
    cout<<sum;
    //cout<<sum/2;
    return 0;
}
