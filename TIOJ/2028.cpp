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

ll n,p;
ll power(ll a,int N){
    ll x=1;
    for(;N;N>>=1,a=a*a%p) if(N&1) x=x*a%p;
    return x;
}
int main(){Rosario
    cin>>n>>p;
    while(n--){
        ll x,k;
        cin>>x>>k;
        if(k&1) cout<<p-power(x,k)<<"\n";
        else cout<<power(x,k)<<"\n";
    }
    return 0;
}
