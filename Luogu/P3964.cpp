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
const int z=1e5+5;
int n,p[z],q[z],x[z],y[z];
pii ac[z];
ll ans=1e18;
 main(){Rosario
    cin>>n;
    int a,b;
    REP1(i,1,n){
        cin>>a>>b;
        x[i]=ac[i].F=a+b;
        y[i]=ac[i].S=a-b;
    }
    sort(x+1,x+1+n); sort(y+1,y+1+n);
    REP1(i,1,n) p[i]=p[i-1]+x[i],q[i]=q[i-1]+y[i];
    REP1(i,1,n){
        int k=lower_bound(x+1,x+1+n,ac[i].F)-x;
        ll s;
        s=k*ac[i].F-p[k]+p[n]-p[k]-(n-k)*ac[i].F;
        k=lower_bound(y+1,y+1+n,ac[i].S)-y;
        s+=k*ac[i].S-q[k]+q[n]-q[k]-(n-k)*ac[i].S;
        ans=min(ans,s);
    }
    cout<<ans/2<<"\n";
    return 0;
}
