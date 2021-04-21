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

const ll mod=1000000007;
struct matrix{
    ll a[2][2];
    matrix(){memset(a,0,sizeof(a));}
    matrix operator*(const matrix &x){
        matrix res;
        REP(k,2) REP(i,2) REP(j,2) res.a[i][j]=(res.a[i][j]+a[i][k]*x.a[k][j]%mod)%mod;
        return res;
    }
}p[66],A;
ll t,n;
void power(ll N){
    for(ll i=0;i<64;++i) 
        if(N>>i&1) 
            A=A*p[i];
}
int main(){Rosario
    p[0].a[1][1]=p[0].a[1][0]=p[0].a[0][1]=1;
    for(register ll i=1;i<64;++i) p[i]=p[i-1]*p[i-1];
    cin>>t;
    while(t--){
        A.a[0][0]=A.a[0][1]=A.a[1][0]=A.a[1][1]=0;
        cin>>A.a[0][0]>>A.a[0][1]>>n;
        A.a[0][0]%=mod; A.a[0][1]%=mod;
        power(n-1);
        cout<<A.a[0][0]%mod<<"\n";
    }
    return 0;
}
