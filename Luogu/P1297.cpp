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


const int z=10000005,mod=100000001;
int a[z],n,x,y,c;
double ans;
int main(){Rosario
    cin>>n>>x>>y>>c>>a[1];
    REP1(i,2,n) a[i]=((ll)a[i-1]*x+y)%mod;
    REP1(i,1,n) a[i]=a[i]%c+1;
    a[0]=a[n];
    REP1(i,1,n) ans+=1./max(a[i],a[i-1]);
    cout<<fixed<<setprecision(3)<<ans<<"\n";
    return 0;
}
