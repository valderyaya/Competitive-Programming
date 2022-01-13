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
#define Aincrad ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define lb(x) (x&-x)

int t,n,m,k,a[5005];
signed main(){Aincrad
    cin>>t;
    while(t--){
        cin>>n>>m>>k;
        REP(i,n) cin>>a[i];
        int ans=0;
        k=min(k,m-1);
        REP1(i,0,k){
            int mn=1e9;
            REP(j,m-k) mn=min(mn,max(a[i+j],a[i+j+n-m]));
            ans=max(ans,mn);
        }
        cout<<ans<<"\n";
    }
    return 0;
}
