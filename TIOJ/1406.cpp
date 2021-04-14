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

const int z=1e5+1;
ll n,a[z],p[z];
bool ck(ll x){
    ll res=0;
    REP1(i,1,n){
        if(res) res-=p[i]-p[i-1];
        res+=a[i]-x;
    }
    return res>=0;
}
int main(){Rosario
    while(cin>>n){
        ll l=1e18,r=0,mid;
        REP1(i,1,n){
            cin>>p[i]>>a[i];
            r=max(r,a[i]); l=min(l,a[i]);
        }++r;
        while(r-l>1){
            mid=l+r>>1;
            if(ck(mid)) l=mid;
            else r=mid;
        }
        cout<<l<<"\n";
    }
    return 0;
}
