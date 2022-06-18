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

int n,mx,a[100005],f[100005],s,m;
signed main(){Rosario
    cin>>n;
    REP(i,n) cin>>a[i],s+=a[i];
    sort(a,a+n); m=s/2;
    for(int i=n;i;--i){
        for(int j=s;j>=a[i];--j){
            f[j]=max(f[j],f[j-a[i]]+a[i]);
            if(f[j]>m&&f[j]-a[i]<=m) mx=max(mx,f[j]);
        }
    }cout<<mx<<"\n";
    return 0;
}
