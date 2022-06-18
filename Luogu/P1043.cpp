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
//#define lb(x) (x&-x)

const int mod=10,inf=1e9;
int n,m,a[105],fx[101][101][11],fn[101][101][11];
int rev(int x){return (x%mod+mod)%mod;}
int main(){Rosario
    cin>>n>>m;
    REP1(i,1,n) cin>>a[i],a[n+i]=a[i];
    REP1(i,1,n+n) a[i]+=a[i-1];
    REP1(i,1,n*2) REP1(j,i,2*n) fx[i][j][1]=fn[i][j][1]=rev(a[j]-a[i-1]);
    REP1(k,2,m) REP1(i,1,2*n) for(int j=i+k-1;j<=2*n;++j) fn[i][j][k]=inf;
    REP1(l,2,m) REP1(i,1,2*n) for(int j=i+l-1;j<=2*n;++j) for(int k=i+l-2;k<j;++k){
        fx[i][j][l]=max(fx[i][j][l],fx[i][k][l-1]*rev(a[j]-a[k]));
        fn[i][j][l]=min(fn[i][j][l],fn[i][k][l-1]*rev(a[j]-a[k]));
    } 
    int mx=0,mn=inf;
    REP1(i,1,n) mx=max(mx,fx[i][n+i-1][m]),mn=min(mn,fn[i][n+i-1][m]);
    cout<<mn<<'\n'<<mx;
    return 0;
}
