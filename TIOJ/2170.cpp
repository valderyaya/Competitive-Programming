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

#define int ll
int n,m,a[105][105];
int pw(int x,int y){
    int res=1;
    for(;y;y>>=1,x=x*x%m) if(y&1) res=res*x%m;
    return res%m;
}
void init(int &x){
    x%=m;
    if(x<0) x+=m;
}
void gauss(){
    REP(i,n){
        int mx=i;
        for(int j=i+1;j<n;++j) if(a[mx][i]<a[j][i]) mx=j;
        if(mx!=i) swap(a[mx],a[i]);
        REP(j,n){
            if(i==j) continue;
            int df=a[j][i]*pw(a[i][i],m-2)%m;
            for(int k=i;k<=n;++k){
                a[j][k]-=df*a[i][k]%m;
                init(a[j][k]);
            }
        }
    }
    REP(i,n) cout<<a[i][n]*pw(a[i][i],m-2)%m<<' ';
}
 main(){Rosario
    cin>>n>>m;
    REP(i,n) cin>>a[i][n];
    REP(j,n) REP(i,n) cin>>a[i][j];
    gauss();
    //REP(i,n) cout<<a[i][n]/a[i][i]<<endl;
    return 0;
}
