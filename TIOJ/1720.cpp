//#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#include<bits/stdc++.h>
//#include<bits/extc++.h>
//using namespace __gnu_pbds;
using namespace std;
#define F first
#define S second
typedef long long ll;
#define REP(i,n) for(int i=0;i<(n);++i)
#define REP1(i,a,b) for(int i=(a);i<=(b);++i)
#define em emplace_back
#define mkp make_pair
#define pii pair<int,int>
#define pll pair<ll,ll>
#define Rosario ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define lb(x) (x&-x)

#define int ll
const int z=100005; 
int tmp[z],n,m,b[z]={};
pii a[z];
void add(int x){for(;x<=m;x+=lb(x))b[x]++;}
int que(int x){
    int r=0;
    for(;x;x-=lb(x)) r+=b[x];
    return r;
}
main(){Rosario
    cin>>n>>m; int sum=0;
    REP(i,n) cin>>a[i].F;
    REP(i,n) cin>>a[i].S,tmp[i]=a[i].S;
    sort(tmp,tmp+n); sort(a,a+n);
    m=unique(tmp,tmp+n)-tmp;
    for(int i=n-1;~i;--i){
        int x=lower_bound(tmp,tmp+m,a[i].S)-tmp+1;
        sum+=que(x-1); add(x);
    }cout<<sum<<"\n";
    return 0;
}
