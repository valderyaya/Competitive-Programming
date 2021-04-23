#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
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

int n,a[2048][2048],b[2048][2048],c[2048][2048];
int main(){Rosario
    cin>>n;
    REP(i,n) REP(j,n) cin>>a[i][j];
    REP(i,n) REP(j,n) cin>>b[i][j];
    REP(i,n) REP(j,n) REP(k,n) c[i][j]+=a[i][k]*b[k][j];
    REP(i,n) REP(j,n) cout<<c[i][j]<<" \n"[j==n-1];
    return 0;
}
