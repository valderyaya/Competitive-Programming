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
vector<int> v;
pii a[z];
int n,b[z],d[z];
signed main(){Rosario
    cin>>n;
    REP1(i,1,n) cin>>a[i].F>>b[i],a[i].S=b[i];
    sort(a+1,a+1+n); sort(b+1,b+1+n);
    REP1(i,1,n) d[i]=lower_bound(b+1,b+1+n,a[i].S)-b;
    REP1(i,1,n){
        if(v.empty()||v.back()<d[i]) v.em(d[i]);
        else v[lower_bound(ALL(v),d[i])-v.begin()]=d[i];
    }
    cout<<v.size()<<"\n";
    return 0;
}
