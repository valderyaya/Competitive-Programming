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

const int inf=2e9;
int m,f[205][205][2],pre=0,now=1,dis[205][205],n,a[1005];
int main(){Rosario
    cin>>n;
    REP1(i,1,n) REP1(j,1,n) cin>>dis[i][j],f[i][j][1]=f[i][j][0]=inf;
    for(m=1;cin>>a[m];++m);
    f[2][3][0]=f[3][2][0]=dis[1][a[1]];
    f[1][3][0]=f[3][1][0]=dis[2][a[1]];
    f[1][2][0]=f[2][1][0]=dis[3][a[1]];
    for(int k=1;k<m-1;++k){
        REP1(i,1,n) REP1(j,1,n){
            f[i][j][now]=min(f[i][j][now],f[i][j][pre]+dis[a[k]][a[k+1]]);
            f[i][a[k]][now]=min(f[i][a[k]][now],f[i][j][pre]+dis[j][a[k+1]]);
            f[a[k]][j][now]=min(f[a[k]][j][now],f[i][j][pre]+dis[i][a[k+1]]);
            f[i][j][pre]=inf;
        }
        swap(pre,now);
    }
    int ans=inf;
    REP1(i,1,n) REP1(j,1,n) ans=min(ans,f[i][j][pre]);
    cout<<ans<<"\n";
    return 0;
}
