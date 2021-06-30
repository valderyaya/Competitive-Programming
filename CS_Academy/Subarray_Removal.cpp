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

ll n,a[100005],ans=-1e18,pre[100005],sub[100005];
int main(){Rosario
    cin>>n;
    REP1(i,1,n) cin>>a[i],ans=max(ans,a[i]);
    pre[1]=a[1], sub[n]=a[n];
    REP1(i,2,n) pre[i]=max(pre[i-1]+a[i],a[i]);
    REP1(i,2,n) pre[i]=max(pre[i],pre[i-1]);
    for(int i=n-1;i;--i) sub[i]=max(a[i],sub[i+1]+a[i]);
    for(int i=n-1;i;--i) sub[i]=max(sub[i],sub[i+1]);
    REP1(i,2,n-1) ans=max(ans,pre[i-1]+sub[i+1]);
    cout<<ans<<"\n";
    return 0;
}
