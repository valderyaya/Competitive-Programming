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

const int z=2e5+5;
const long double eps=1e-12;
int n,m;
long double c[z],a[z],b[z];
bool check(long double mid){
    REP1(i,1,n) c[i]=c[i-1]+a[i]-b[i]*mid;
    deque<int> dq; dq.emplace_back(0);
    bool ck=0;
    REP1(i,1,n){
        while(dq.size()>1&&i-dq[1]>=m) dq.pop_front();
        if(i-dq.front()>=m&&c[i]>=c[dq.front()]) ck=1;
        if(c[i]<c[dq.back()]) dq.emplace_back(i);
    }
    return ck;
}
void solve(){
    long double l=0,r=2147483647,mid;
    while(r-l>eps){
        mid=(l+r)/2;
        if(check(mid)) l=mid;
        else r=mid;
    }
    cout<<fixed<<setprecision(8)<<l<<"\n";
}
int main(){Rosario
    cin>>n>>m;
    REP1(i,1,n) cin>>a[i];
    REP1(i,1,n) cin>>b[i];
    solve();
    return 0;
}
