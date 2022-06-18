//#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#include<bits/stdc++.h>
//#include<bits/extc++.h>
//using namespace __gnu_pbds;
using namespace std;
#define F first
#define S second
typedef long long ll;
#define REP(i,n) for(int i=0;i<(n);++i)
#define REP1(i,a,b) for(int i=(a);i<=(b);++i)
#define em emplace_back
#define mkp make_pair
#define pb push_back
#define ALL(x) (x).begin(),(x).end()
#define pii pair<int,int>
#define pll pair<ll,ll>
#define Rosario ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//#define lb(x) (x&-x)

ll n,k,a[1000005],sum=0,mx=0;
int main(){Rosario
    cin>>n>>k;
    if(k<0) k=0;
    if(k>=n-1) k=n-1; 
    REP1(i,1,n-1) cin>>a[i],sum+=a[i],a[i]+=a[i-1];
    for(int i=k;i<=n-1;++i) mx=max(mx,a[i]-a[i-k]);
    cout<<sum-mx<<"\n";
    return 0;
}
