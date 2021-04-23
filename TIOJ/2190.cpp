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

ll md;
ll power(ll x,ll n){
    ll res=1;
    for(x%=md;n;n>>=1,x=(x*x)%md) if(n&1) res=(res*x)%md;
    return res;
}
signed main(){Rosario
    ll t,a,b,x1,x2,y1,y2;
    cin>>t;
    while(t--){
        cin>>md>>a>>b>>x1>>y1>>x2>>y2;
        ll m=((y2-y1)*power(x2-x1,md-2)%md+md)%md;
        ll m2=m*m%md;
        ll x3=((m2-x1-x2)%md+md)%md;
        ll k=((y1-m*x1)%md+md)%md;
        ll y3=((m*x3+k)%md+md)%md;
        cout<<x3<<' '<<y3<<"\n";
    }
    return 0;
}
