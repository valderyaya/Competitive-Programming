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

int n,f[105][105],s[105];
signed main(){Rosario
    cin>>n;
    REP1(i,1,n) cin>>s[i],f[i][i]=s[i],s[i]+=s[i-1];
    REP1(i,1,n) for(int j=i-1;j;--j) f[j][i]=max(s[i]-s[j-1]-f[j+1][i],s[i]-s[j-1]-f[j][i-1]);
    cout<<f[1][n]<<' '<<s[n]-f[1][n]<<"\n";
    return 0;
}
