#include<bits/stdc++.h>
using namespace std;
#define valder ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define ll long long
#define F first
#define S second
#define ALL(x) x.begin(),x.end()
#define pii pair<int,int>
#define REP(i,n) for(int i=0;i<n;++i)
#define REP1(i,a,b) for(int i=a;i<=b;++i)
#define em emplace_back
#define lb(x) x&-x
#define pll pair<ll,ll>
#define mkp make_pair

ll n,a,b,c,an,bn,cn,sn,sa,sb,sc;
signed main(){valder
    cin>>n>>a>>b;
    sn=n*(n+1)/2;
    an=n/a, bn=n/b;
    sa=an*(a+a+(an-1)*a)/2;
    sb=bn*(b+b+(bn-1)*b)/2;
    c=a*b/__gcd(a,b);
    cn=n/c;
    sc=cn*(c+c+(cn-1)*c)/2;
    cout<<sn-sa-sb+sc;
    return 0;
}
