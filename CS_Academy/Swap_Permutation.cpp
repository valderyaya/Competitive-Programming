//#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#include<bits/stdc++.h>
//#include<bits/extc++.h>
//using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
#define F first
#define S second
#define pb push_back
#define REP(i,n) for(register int i=0;i<(n);++i)
#define REP1(i,a,b) for(register int i=(a);i<=(b);++i)
#define em emplace_back
#define ALL(x) (x).begin(),(x).end()
#define mkp make_pair
#define pii pair<int,int>
#define pll pair<ll,ll>
#define Rosario ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//#define lb(x) (x&-x)

pii a[100005];
int n,m,k,p[100005],e[100005];
int main(){//Rosario
    cin>>n>>m>>k;
    REP1(i,1,m) cin>>a[i].F>>a[i].S;
    p[0]=1,e[n+1]=k;
    REP1(i,1,n) p[i]=((p[i-1]==a[i].F||p[i-1]==a[i].S)?p[i-1]^a[i].F^a[i].S:p[i-1]);
    for(int i=n;i;--i) e[i]=((e[i+1]==a[i].F||e[i+1]==a[i].S)?e[i+1]^a[i].F^a[i].S:e[i+1]);
    REP1(i,1,n) if(p[i-1]==e[i+1]) return cout<<i,0;
    cout<<-1;
    return 0;
}
