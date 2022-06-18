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

const int z=1e6+5;
ll n,pos[z],p[z],c[z],a[z],b[z],q[z],l,r,f[z];
double cal(ll j,ll k){
    return (double)(f[j]+b[j]-f[k]-b[k])/(a[j]-a[k]);
}
int main(){Rosario
    cin>>n;
    REP1(i,1,n) cin>>pos[i]>>p[i]>>c[i];
    REP1(i,1,n) a[i]=a[i-1]+p[i];
    REP1(i,1,n) b[i]=b[i-1]+p[i]*pos[i];
    REP1(i,1,n){
        while(l<r&&cal(q[l+1],q[l])<pos[i]) ++l;
        f[i]=f[q[l]]+pos[i]*(a[i]-a[q[l]])-(b[i]-b[q[l]])+c[i];
        while(l<r&&cal(q[r],q[r-1])>cal(i,q[r])) --r;
        q[++r]=i;
    }
    cout<<f[n]<<"\n";
    return 0;
}
