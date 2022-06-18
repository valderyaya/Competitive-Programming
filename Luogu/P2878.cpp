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

ll n,s[100005];
struct qq{
    ll x,v;
    bool operator<(const qq &a){
        return x*a.v<a.x*v;
    }
}a[100005];
int main(){Rosario
    cin>>n;
    REP1(i,1,n) cin>>a[i].x>>a[i].v;
    sort(a+1,a+1+n);
    REP1(i,1,n) s[i]=s[i-1]+a[i].v;
    ll sum=0;
    REP1(i,1,n) sum+=2*a[i].x*(s[n]-s[i]);
    cout<<sum<<"\n";
    return 0;
}
