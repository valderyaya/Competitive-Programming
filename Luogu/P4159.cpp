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

const int md=2009;
struct qwq{
    int n,a[100][100];
    qwq(){memset(a,0,sizeof(a));}
    qwq(int r):n(r){memset(a,0,sizeof(a));}
    void clear(){
        REP1(i,1,n) a[i][i]=1;
    }
    qwq operator*(const qwq &x)const{
        qwq res(x.n);
        REP1(k,1,n) REP1(i,1,n) REP1(j,1,n) res.a[i][j]=(res.a[i][j]+a[i][k]*x.a[k][j])%md;
        return res;
    }
    qwq operator^(int p)const{
        qwq res(n),x=*this;
        res.clear();
        for(;p;p>>=1,x=x*x) if(p&1) res=res*x;
        return res;
    }
}v;
int n,t,x;
int pos(int i,int j){return i+j*n;}
signed main(){//Rosario
    scanf("%d%d",&n,&t);
    v.n=n*9;
    REP1(i,1,n){
        REP1(j,1,8) v.a[pos(i,j)][pos(i,j-1)]=1;
        REP1(j,1,n){
            scanf("%1d",&x);
            if(x) v.a[i][pos(j,x-1)]=1;
        }
    }
    v=v^t;
    printf("%d\n",v.a[1][n]);
    return 0;
}
