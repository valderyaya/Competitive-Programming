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
//#define lb(x) (x&-x)

const int mod=2017;
struct matrix{
    int n,m,c[105][105];
    matrix(){n=m=0; memset(c,0,sizeof(c));}
    matrix operator*(const matrix &x){
        matrix res;  res.n=n, res.m=x.m;
        for(int i=0;i<=res.n;++i)
            for(int j=0;j<=res.m;++j)
                for(int k=0;k<=m;++k)
                    res.c[i][j]=(res.c[i][j]+c[i][k]*x.c[k][j]%mod)%mod;
        return res;
    }
};
int n,m,t;
matrix power(matrix &x,int N){
    matrix res; res.n=x.n, res.m=x.m;
    REP1(i,0,n) res.c[i][i]=1;
    for(;N;N>>=1,x=x*x) if(N&1) res=res*x;
    return res;
}
int main(){Rosario
    int x,y;
    matrix a;
    cin>>n>>m; a.n=a.m=n;
    while(m--) cin>>x>>y,a.c[x][y]=a.c[y][x]=1;
    REP1(i,0,n) a.c[i][i]=a.c[i][0]=1;
    cin>>t;
    matrix ans=power(a,t);
    int mx=0;
    REP1(i,0,n) mx=(mx+ans.c[1][i])%mod;
    cout<<mx<<"\n";
    return 0;
}
