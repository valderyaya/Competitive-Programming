//#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#include<bits/stdc++.h>
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
    int x,y,h;
    bool operator<(const qq &a)const{
        return (x*x+y*y)<(a.x*a.x+a.y*a.y);
    }
}q[100006];
int n,l[100005],r[100005];
int main(){Rosario
    cin>>n;
    REP(i,n) cin>>q[i].x>>q[i].y>>q[i].h;
    sort(q,q+n);
    l[0]=q[0].h;r[n-1]=q[n-1].h;
    for(int i=1;i<n;i++) l[i]=max(l[i-1],q[i].h);
    for(int i=n-2;i>=0;i--) r[i]=min(r[i+1],q[i].h);
    int mx=0;
    REP(i,n) mx=max(mx,l[i]-r[i]);
    cout<<mx<<"\n";
//    system("pause");
    return 0;
}
