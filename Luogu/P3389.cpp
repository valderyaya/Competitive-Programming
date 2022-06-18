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

double a[105][105];
int n;
void solve(){
    REP(i,n){
        int mx=i;
        for(int j=i+1;j<n;++j) if(a[mx][i]<a[j][i]) mx=i;
        swap(a[mx],a[i]);
        if(!a[i][i]) cout<<"No Solution",exit(0);
        REP(j,n){
            if(i==j) continue;
            double df=a[j][i]/a[i][i];
            for(int k=i+1;k<=n;++k) a[j][k]-=df*a[i][k];
        }
    }
    REP(i,n) cout<<fixed<<setprecision(2)<<a[i][n]/a[i][i]<<"\n";
}
signed main(){Rosario
    cin>>n;
    REP(i,n) REP(j,n+1) cin>>a[i][j];
    solve();
    return 0;
}
