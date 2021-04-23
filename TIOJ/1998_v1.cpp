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


ll n,m,a,b,c,d,x;
vector<pll> v;
int op(ll t){
    ll l=0,mid,r=v.size();
    while(r-l>1){
        mid=l+r>>1;
        if(t<v[mid].F) r=mid;
        else l=mid;
    }return v[l].F<=t&&t<=v[l].S;
}
int main(){//Rosario
    scanf("%lld %lld",&n,&m);
    REP(i,n){
        scanf("%lld.%lld.%lld.%lld/%lld",&a,&b,&c,&d,&x);
        ll t=a; t=t*256+b; t=t*256+c;t=t*256+d; t>>=(32-x);
        ll e=t<<(32-x);
        for(int i=0;i<32-x;i++) t<<=1,++t;
        v.em(mkp(e,t));
    }sort(ALL(v));
    REP1(i,1,v.size()-1) v[i].S=max(v[i].S,v[i-1].S);
    while(m--){
        scanf("%lld.%lld.%lld.%lld",&a,&b,&c,&d);
        ll t=a; t=t*256+b; t=t*256+c;t=t*256+d;
        cout<<(op(t)?"TRUE":"FALSE")<<"\n";
    }
    return 0;
}
