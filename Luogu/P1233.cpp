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
#define wait system("pause");

struct qq{
    int w,h;
    bool operator<(const qq &x)const{
        return w==x.w?h>x.h:w>x.w;
    }
}a[5005];
vector<int> v;
int main(){Rosario
    int n;
    cin>>n;
    REP(i,n) cin>>a[i].w>>a[i].h;
    sort(a,a+n);
    REP(i,n){
        if(v.empty()||v.back()<a[i].h) v.em(a[i].h);
        else v[lower_bound(ALL(v),a[i].h)-v.begin()]=a[i].h;
    }cout<<v.size()<<"\n";
//    system("pause");
    return 0;
}
