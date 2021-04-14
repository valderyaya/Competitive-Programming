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

typedef unsigned long long llu;
const llu mod=1LL<<32;
vector<vector<llu>> a,b,c(2,vector<llu>(2));
void mul(vector<vector<llu>> &x,vector<vector<llu>> &y){
    REP(i,2) REP(j,2) c[i][j]=(x[i][0]*y[0][j]%mod+x[i][1]*y[1][j]%mod)%mod;
    x.swap(c);
}
int main(){Rosario
    ll n,x,y,xx,yy;
    while(cin>>n,n>=0){
        cin>>x>>y>>xx>>yy;
        a={{0,1},{xx,yy}};
        b={{1,0},{0,1}};
        for(;n;mul(a,a),n>>=1) if(n&1) mul(b,a);
        cout<<(ll)(x*b[0][0]%mod+y*b[0][1]%mod)%mod<<"\n";
    }
    return 0;
}
