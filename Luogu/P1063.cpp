//#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#include<bits/stdc++.h>
//#include<bits/extc++.h>
//using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
#define F first
#define S second
#define pb push_back
#define em emplace_back
#define REP(i,n) for(register int i=0;i<(n);++i)
#define REP1(i,a,b) for(register int i=(a);i<=(b);++i)
#define ALL(x) (x).begin(),(x).end()
#define pii pair<int,int>
#define pll pair<ll,ll>
#define Rosario ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//#define lb(x) (x&-x)

const int z=105;
int f[z<<1][z<<1],n,a[z<<1],ans;
int main(){Rosario
    cin>>n;
    REP1(i,1,n) cin>>a[i],a[i+n]=a[i];
    REP1(i,2,n*2)
        for(int j=i-1;i-j<n&&j;--j)
            for(int k=j;k<i;++k)
                ans=max(ans,f[j][i]=max(f[j][i],f[j][k]+f[k+1][i]+a[j]*a[i+1]*a[k+1]));
    cout<<ans;
    return 0;
}
