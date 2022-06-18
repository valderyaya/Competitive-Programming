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
#define Alicization ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define lb(x) (x&-x)

ll n,m,a[1000006];
ll ck(ll md){
    ll res=0;
    REP(i,n) res+=max(a[i]-md,0LL);
    return res;
}
signed main(){Alicization
    cin>>n>>m;
    REP(i,n) cin>>a[i];
    ll l=1,r=2e9,mid;
    while(l<r){
        mid=l+r>>1;
        if(ck(mid)>=m) l=mid+1;
        else r=mid;
    }
    cout<<l-1<<"\n";
    return 0;
}
