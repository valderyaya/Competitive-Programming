//#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#include<bits/stdc++.h>
//#include<bits/extc++.h>
//using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
#define F first
#define S second
#define pb push_back
#define em emplace_back
#define REP(i,n) for(register int i=0;i<(n);++i)
#define REP1(i,a,b) for(register int i=(a);i<=(b);++i)
#define ALL(x) (x).begin(),(x).end()
#define pii pair<int,int>
#define pll pair<ll,ll>
#define Rosario ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//#define lb(x) (x&-x)

ll n,ans,sum=1,a[100005],b[100005];
signed main(){Rosario
    cin>>n;
    REP1(i,1,n) cin>>a[i]>>b[i];
    ans=b[1];
    REP1(i,1,n-1){
        sum=sum*a[i]/__gcd(sum,a[i]);
        while(ans%a[i+1]!=b[i+1]) ans+=sum;
    } cout<<ans;
    return 0;
}
