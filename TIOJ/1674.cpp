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
#define pii pair<int,int>
#define pll pair<ll,ll>
#define Rosario ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//#define lb(x) (x&-x)

const ll mod=1000000009,md=500000005;
ll n,ans=0,r,l,x;
int main(){Rosario
    cin>>n;
    for(ll i=1;i*i<n;++i){
        r=n/i, l=n/(i+1)+1;
        x=(n%r+n%l)%mod; r=(r-l+1)%mod;
        ans+=(((x*r)%mod)*md)%mod;
        if(ans>mod) ans-=mod;
    }
    for(ll i=2;i<l;++i) ans+=n%i,ans-=(ans>mod?mod:0);
    cout<<ans<<"\n";
    return 0;
}
