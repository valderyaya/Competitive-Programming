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

const int z=1e5+5;
int sum[z],n,sub[z],pos[z];
struct qq{
    int x,v;
    bool operator<(const qq &a){return v>a.v;}
}q[z];
int main(){Rosario
    cin>>n;
    REP1(i,1,n) cin>>q[i].x;
    REP1(i,1,n) cin>>q[i].v;
    sort(q+1,q+1+n);
    REP1(i,1,n) sum[i]=sum[i-1]+q[i].v;
    REP1(i,1,n) pos[i]=max(pos[i-1],q[i].x*2);
    for(int i=n;i;--i) sub[i]=max(sub[i+1],q[i].v+q[i].x*2);
    REP1(i,1,n) cout<<max(sum[i]+pos[i],sum[i-1]+sub[i])<<"\n";
    return 0;
}
