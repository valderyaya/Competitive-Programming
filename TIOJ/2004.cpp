//#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#include<bits/stdc++.h>
//#include<bits/extc++.h>
//using namespace __gnu_pbds;
using namespace std;
#define F first
#define S second
typedef long long ll;
#define REP(i,n) for(register int i=0;i<(n);++i)
#define REP1(i,a,b) for(register int i=(a);i<=(b);++i)
#define em emplace_back
#define mkp make_pair
#define pb push_back
#define ALL(x) (x).begin(),(x).end()
#define pii pair<int,int>
#define pll pair<ll,ll>
#define Rosario ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//#define lb(x) (x&-x)

#define int ll
const int mod=1e9+7;
int power(int a,int n){
    int res=1;
    for(;n;n>>=1,a=a*a%mod) if(n&1) res=res*a%mod;
    return res;
}
int t,n;
main(){Rosario
    cin>>t;
    while(t--) cin>>n,cout<<power(4,n-1)<<"\n";
    return 0;
}
