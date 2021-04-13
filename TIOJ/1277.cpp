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

#define int ll
int n,a[505][505],mx=0;
main(){Rosario
    cin>>n;
    REP1(i,1,n) REP1(j,1,n) cin>>a[i][j],a[i][j]+=a[i-1][j];
    REP1(i,1,n) for(int j=i;j<=n;++j){
        int x=0;
        REP1(k,1,n){
            x+=a[j][k]-a[i-1][k];
            mx=max(mx,x);
            if(x<0) x=0;
        }
    }cout<<mx<<"\n";
    return 0;
}
