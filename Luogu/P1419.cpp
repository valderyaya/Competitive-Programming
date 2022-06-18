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

const int z=1e5+5;
const double eps=1e-7;
int n,s,t;
double l=z,r=-z,sum[z],a[z];
deque<int> dq;
bool jd(double x){
    REP1(i,1,n) sum[i]=sum[i-1]+a[i]-x;
    dq.clear();
    for(int i=s,p=0;i<=n;++i,++p){
        while(!dq.empty()&&sum[dq.back()]>sum[p]) dq.pop_back();
        dq.push_back(p);
        while(dq.front()<i-t) dq.pop_front();
        if(sum[i]-sum[dq.front()]>=0) return 1;
    }
    return 0;
}
signed main(){Rosario
    cin>>n>>s>>t;
    REP1(i,1,n) cin>>a[i],l=min(l,a[i]),r=max(r,a[i]);
    while(r-l>eps){
        double mid=(l+r)/2;
        if(jd(mid)) l=mid;
        else r=mid;
    }
    cout<<fixed<<setprecision(3)<<l<<"\n";
    return 0;
}
