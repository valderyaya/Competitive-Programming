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
const int z=205,inf=1e18;
int we[z],nn,m,s,t;
struct matrix{
    int n,m,c[z][z];
    matrix operator*(const matrix &x)const{
        matrix res; res.n=n, res.m=x.m;
        REP1(i,1,nn) REP1(j,1,nn) res.c[i][j]=-inf;
        REP1(i,1,res.n)
            REP1(j,1,res.m)
                REP1(k,1,m) res.c[i][j]=max(res.c[i][j],c[i][k]+x.c[k][j]);
        return res;
    }
};
matrix a;
matrix power(matrix &x,int N){
    a.n=a.m=x.n;
    for(;N;N>>=1,x=x*x) if(N&1) a=a*x;
    return a;
}
main(){Rosario
    cin>>nn>>m>>s>>t;
    REP1(i,1,nn) cin>>we[i];
    int x,y; 
    matrix ma;
    ma.n=ma.m=nn;
    REP1(i,1,nn) REP1(j,1,nn) {
        if(i!=j) a.c[i][j]=-inf;
        else a.c[i][j]=0;
        ma.c[i][j]=-inf;
    }
    REP(i,m) cin>>x>>y,ma.c[x][y]=we[y];
    matrix ans=power(ma,t);
    int mx=-inf;
    REP1(i,1,nn) mx=max(mx,ans.c[s][i]);
    cout<<mx<<"\n";
    return 0;
}
