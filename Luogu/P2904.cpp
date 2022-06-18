//#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#include<bits/stdc++.h>
//#include<bits/extc++.h>
//using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
#define F first
#define S second
#define pb push_back
#define REP(i,n) for(int i=0;i<(n);++i)
#define REP1(i,a,b) for(int i=(a);i<=(b);++i)
#define em emplace_back
#define ALL(x) (x).begin(),(x).end()
#define mkp make_pair
#define pii pair<int,int>
#define pll pair<ll,ll>
#define Rosario ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//#define lb(x) (x&-x)

int n,m,f[2505],sum[2505];
int main(){Rosario
    cin>>n>>m;
    REP1(i,1,n) cin>>sum[i],sum[i]+=sum[i-1],f[i]=1e9;
    REP1(i,1,n) sum[i]+=2*m;
    REP1(i,1,n) for(int j=1;j<=i;++j) f[i]=min(f[i],f[i-j]+sum[j]);
    cout<<f[n]-m<<"\n";
    return 0;
}
