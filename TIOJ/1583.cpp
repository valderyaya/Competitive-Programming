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

struct qq{
    string s;
    double w,h;
    bool operator<(const qq &x){return w/h/h>x.w/x.h/x.h;}
}q[10005];
int n;
int main(){Rosario
    cin>>n;
    REP(i,n) cin>>q[i].s>>q[i].w>>q[i].h,q[i].h/=100;
    sort(q,q+n);
    REP(i,min(n,10)) cout<<q[i].s<<"\n";
    return 0;
}
