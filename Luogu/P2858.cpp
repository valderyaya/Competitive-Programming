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

int n,f[2001][2001],a[2001];
int main(){Rosario
    cin>>n;
    REP1(i,1,n) cin>>f[i][i],a[i]=f[i][i],f[i][i]*=n;
    for(int l=2;l<=n;++l) for(int i=1,j=l+i-1;j<=n;++j,++i) 
        f[i][j]=max(f[i+1][j]+(n-l+1)*a[i],f[i][j-1]+(n-l+1)*a[j]);
    cout<<f[1][n]<<"\n";
    return 0;
}
