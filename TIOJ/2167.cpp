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

const int z=5e5+1;
ll X[z],Y[z],suf[z],n;
double sum,ss=0;
const double pi=acos(-1);
int main(){Rosario
    cin>>n;
    REP(i,n) cin>>X[i]>>Y[i];
    REP(i,n) ss+=X[i]*X[i]+Y[i]*Y[i];
    sum=(n-1)*ss; suf[n]=0;
    for(int i=n-1;i>=0;--i) suf[i]=suf[i+1]+X[i];
    REP(i,n-1) sum-=(double)2*X[i]*suf[i+1];
    for(int i=n-1;i>=0;--i) suf[i]=suf[i+1]+Y[i];
    REP(i,n-1) sum-=(double)2*Y[i]*suf[i+1];
    cout<<fixed<<setprecision(9)<<sum/2*pi<<"\n";
    return 0;
}
