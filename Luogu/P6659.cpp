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

ll n,t;
map<ll,pll> mp;
bool a(){
    ll l=1,r=1e9;
    while(l<r){
        ll m=(l+r+1)>>1;
        if(m*m+m>n) r=m-1;
        else l=m;
    }
    if(l*l+l==n) return cout<<l<<' '<<l+1<<"\n",1;
    return 0;
}
bool b(ll o){
    ll l=1,r=2e6;
    while(l<r){
        ll m=(l+r+1)>>1;
        if(m*(m+1)*(m+2)>n) r=m-1;
        else l=m;
    }
    if((l&1LL)!=o) return 0;
    if(l*(l+1)*(l+2)==n) return cout<<l<<' '<<l+2<<'\n',1;
    return 0;
}
void solve(){
    cin>>n;
    if(mp.count(n)) return cout<<mp[n].F<<' '<<mp[n].S<<'\n',void();
    if(a()) return;
    if(b(1)) return;
    if(n*=2,b(0)) return;
    cout<<"NIE\n";
}
signed main(){//Rosario
    for(ll i=1;i<=1000000;++i){
        ll x=i*i+i;
        for(ll j=i+2;;++j){
            x/=__gcd(x,j);
            if(x>1e18/j) break;
            x*=j;
            if(!mp.count(x)) mp[x]={i,j};
        }
    }cin>>t;
    while(t--) solve();
    return 0;
}
