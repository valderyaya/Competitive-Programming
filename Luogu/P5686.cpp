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

const ll mod=1e9+7,z=5e5+5;
ll n,a[z],b[z],sa[z],sb[z],sum[z],ans;
int main(){Rosario
    cin>>n;
    REP1(i,1,n) cin>>a[i],a[i]+=a[i-1],a[i]%=mod;
    REP1(i,1,n) cin>>b[i],b[i]+=b[i-1],b[i]%=mod;
    REP1(i,1,n) sum[i]=(sum[i-1]+a[i]*b[i]%mod)%mod;
    REP1(i,1,n) sa[i]=(sa[i-1]+a[i])%mod;
    REP1(i,1,n) sb[i]=(sb[i-1]+b[i])%mod;
    REP1(i,1,n){
        ll x=((sum[n]-sum[i-1])%mod+mod)%mod;
        ll y=((sa[n]-sa[i-1])%mod+mod)%mod*b[i-1]%mod;
        ll c=((sb[n]-sb[i-1])%mod+mod)%mod*a[i-1]%mod;
        ll d=(n-i+1)*a[i-1]%mod*b[i-1]%mod;
        ans=(ans+((x-y+mod)%mod-c+mod)%mod+d)%mod;
    }cout<<ans;
    return 0;
}
