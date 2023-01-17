//#pragma GCC optimize("unroll-loops, no-stack-protector, Ofast")
#include<bits/stdc++.h>
using namespace std;
#define StarBurstStream ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define ll long long
#define F first
#define S second
#define ALL(x) x.begin(),x.end()
#define pii pair<int,int>
#define REP(i,n) for(int i=0;i<n;++i)
#define REP1(i,a,b) for(int i=a;i<=b;++i)
#define em emplace_back
#define lb(x) x&-x
#define pll pair<ll,ll>
#define mkp make_pair
 
 
const ll mod=1e9+7;
ll n,ans,now=1,x,y;
signed main(){StarBurstStream
    cin>>n;
    while(now<=n){
        x=n/now; y=n/x;
        (ans+=x*((((y-now+1)%mod)*((now+y)%mod)%mod)*500000004%mod)%mod)%=mod;
        now=y+1;
    }
    cout<<ans<<"\n";
}
