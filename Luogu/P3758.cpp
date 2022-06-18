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

const int z=31,mod=2017;
struct matrix{
    int m[z][z];
    matrix operator*(const matrix &x){
        matrix res;
        memset(res.m,0,sizeof(res.m));
        for(int i=0;i<=30;++i)
            for(int j=0;j<=30;++j)
                for(int k=0;k<=30;++k)
                    res.m[i][j]=(res.m[i][j]+m[i][k]*x.m[k][j]%mod)%mod;
        return res;
    }
};
matrix power(matrix &a,int n){
    matrix res;
    memset(res.m,0,sizeof(res.m));
    REP1(i,0,30) res.m[i][i]=1;
    for(;n;n>>=1,a=a*a) if(n&1) res=res*a;
    return res;
}
int n,m;
matrix edge;
int main(){Rosario
    cin>>n>>m;
    int x,y;
    while(m--) cin>>x>>y,edge.m[x][y]=edge.m[y][x]=1;
    for(int i=0;i<=n;++i) edge.m[i][i]=1,edge.m[i][0]=1;
    cin>>y; x=0;
    matrix ans=power(edge,y);
    REP1(i,0,n) x=(x+ans.m[1][i])%mod;
    cout<<x<<"\n";
//    system("pause");
    return 0;
}
