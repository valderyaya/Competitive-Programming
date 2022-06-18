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


const int mod=100003;
int a[1001][1001],n,m;
int main(){Rosario
    cin>>n>>m;
    int x,y;
    while(m--) cin>>x>>y,a[x][y]=-1;
    for(int i=1;i<=n&&a[i][1]!=-1;i++) a[i][1]=1;
    for(int i=1;i<=n&&a[1][i]!=-1;i++) a[1][i]=1;
    REP1(i,2,n) REP1(j,2,n){
        if(a[i][j]==-1) continue;
        a[i][j]=((~a[i][j-1]?a[i][j-1]:0)+(~a[i-1][j]?a[i-1][j]:0))%mod;
    }
    cout<<a[n][n]<<"\n";
    return 0;
}
