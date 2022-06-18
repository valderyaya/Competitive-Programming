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

struct qq{
    int l,r;
    bool operator<(const qq &x)const{
        return l==x.l?r<x.r:l<x.l;
    }
}a[50005];
int n;
int main(){Rosario
    cin>>n;
    REP(i,n) cin>>a[i].l>>a[i].r;
    sort(a,a+n);
    int l=a[0].l,r=a[0].r;
    for(int i=1;i<n;++i){
        if(r<a[i].l){
            cout<<l<<' '<<r<<"\n";
            l=a[i].l,r=max(r,a[i].r);
        }else r=max(r,a[i].r);
        if(i==n-1) cout<<l<<' '<<r<<"\n";
    }
    return 0;
}
