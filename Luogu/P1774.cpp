//#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#include<bits/stdc++.h>
//#include<bits/extc++.h>
//using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
#define F first
#define S second
#define pb push_back
#define REP(i,n) for(int i=0;i<(n);++i)
#define REP1(i,a,b) for(int i=(a);i<=(b);++i)
#define em emplace_back
#define ALL(x) (x).begin(),(x).end()
#define mkp make_pair
#define pii pair<int,int>
#define pll pair<ll,ll>
#define Rosario ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define lb(x) (x&-x)

ll n,b[500005],a[500005],c[500005];
void add(int x){
    for(;x<=n;x+=lb(x)) b[x]++;
}
int que(int x){
    int res=0;
    for(;x;x-=lb(x)) res+=b[x];
    return res;
}
int main(){Rosario
    cin>>n;
    REP(i,n) cin>>a[i],c[i]=a[i];
    sort(c,c+n);
    ll cnt=0;
    REP(i,n){
        a[i]=upper_bound(c,c+n,a[i])-c;
        add(a[i]);
        cnt+=i+1-que(a[i]);
    }
    cout<<cnt<<"\n";
    return 0;
}
