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
#define lb(x) (x&-x)

#define int ll
const int z=5e4;
int n,ans,bit[2][z+5];
pii a[z+5];
void add(int x,int v){
    for(;x<=z;x+=lb(x)){
        bit[0][x]+=v;
        bit[1][x]++;
    }
}
pii qry(int x){
    int i=0,j=0;
    for(;x;x-=lb(x)) i+=bit[0][x],j+=bit[1][x];
    return mkp(i,j);
}
signed main(){Rosario
	cin>>n;
    REP1(i,1,n) cin>>a[i].F>>a[i].S;
    sort(a+1,a+n+1);
    add(a[1].S,a[1].S);
    REP1(i,2,n){
        pii y,x=qry(a[i].S);
        ans+=(x.S*a[i].S-x.F)*a[i].F;
        y=qry(z); y.F-=x.F, y.S-=x.S;
        ans+=(y.F-y.S*a[i].S)*a[i].F;
        add(a[i].S,a[i].S);
    }
    cout<<ans<<"\n";
    return 0;
}
