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

#define int ll
int n,m,p[1000005];
struct qq{
    int x,y;
    bool operator<(const qq &a){return x<a.x;}
}q[1000005];
main(){Rosario
    cin>>n;
    REP(i,n) cin>>p[i];
    cin>>m;sort(p,p+n);
    REP(i,m) cin>>q[i].x>>q[i].y;
    sort(q,q+m); int sum=0;
    for(int i=0,j=0;i<n;i++){
        for(;q[j].x<p[i]&&j<m;++j);
        if(j==m) return cout<<"Impossible.",0;
        sum+=q[j++].y;
    }cout<<sum<<"\n";
    return 0;
}
