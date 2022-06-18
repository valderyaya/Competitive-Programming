//#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#include<bits/stdc++.h>
//#include<bits/extc++.h>
//using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
#define F first
#define S second
#define pb push_back
#define em emplace_back
#define REP(i,n) for(register int i=0;i<(n);++i)
#define REP1(i,a,b) for(register int i=(a);i<=(b);++i)
#define ALL(x) (x).begin(),(x).end()
#define pii pair<int,int>
#define pll pair<ll,ll>
#define Rosario ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define lb(x) (x&-x)


ll n,m;
struct qwq{
    ll a[2][2];
    ll* operator[](int x){return a[x];}
    qwq(){memset(a,0,sizeof(a));}
    qwq operator*(qwq x){
        qwq res;
        REP(k,2) REP(i,2) REP(j,2) res[i][j]=(res[i][j]+(a[i][k]%m*x[k][j]%m)%m)%m;
        return res;
    }
}a,b;
void power(ll N){
    for(;N;N>>=1,b=b*b) if(N&1) a=a*b;
}
int main(){Rosario
    cin>>b[1][1]>>b[0][1]>>a[0][0]>>a[0][1]>>n>>m;
    b[0][1]%=m,b[1][1]%=m,a[0][0]%=m,a[0][1]%=m;b[1][0]=1;
    if(n<=2) cout<<a[0][n-1]<<"\n";
    else{
        power(n-2);
        cout<<a[0][1]%m<<"\n";
    }
    return 0;
}
