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
#define lb(x) (x&-x)

int n,a[200005];
int main(){Rosario
    cin>>n;
    REP1(i,1,n) cin>>a[i];
    sort(a+1,a+1+n);
    n=unique(a+1,a+1+n)-a-1;
    if(n<=1) cout<<"-1";
    else cout<<max(a[n-2],a[n]%a[n-1]);
    return 0;
}
