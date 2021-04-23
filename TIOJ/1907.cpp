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


int t,n;
pii a[20005];
bool cmp2(pii a,pii b){return a.F==b.F?a.S>b.S:a.F<b.F;}
bool cmp(pii a,pii b){return a.S<b.S;}
int lis(){
    vector<pii> v; v.em(a[0]);
    REP1(i,1,n-1)
        if(cmp(v.back(),a[i])) v.em(a[i]);
        else v[lower_bound(ALL(v),a[i],cmp)-v.begin()]=a[i];
    return v.size();
}
int main(){Rosario
    cin>>t;
    while(t--){
        cin>>n;
        REP(i,n) cin>>a[i].F>>a[i].S;
        sort(a,a+n,cmp2); cout<<lis()<<"\n";
    }
    return 0;
}
