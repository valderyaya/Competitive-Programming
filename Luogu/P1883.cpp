//#pragma GCC optimize("unroll-loops, no-stack-protector, Ofast")
#include<bits/stdc++.h>
using namespace std;
#define StarBurstStream ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define ll long long
#define F first
#define S second
#define ALL(x) x.begin(),x.end()
#define pii pair<int,int>
#define REP(i,n) for(int i=0;i<n;++i)
#define REP1(i,a,b) for(int i=a;i<=b;++i)
#define em emplace_back
#define lb(x) x&(-x)
#define pll pair<ll,ll>
#define mkp make_pair
#define ull unsigned long long


const double eps = 1e-12;
int t, n, a[10001], b[10001], c[10001];
double f(double x, int i){
    return x*x*a[i] + x*b[i] +c[i];
}
double maxmum(double x){
    double ret = f(x, 0);
    for(int i = 1; i < n; ++i)
        ret = max(ret, f(x, i));
    return ret;
}
signed main(){StarBurstStream
    cin>>t;
    while(t--){
        cin >> n;
        for(int i=0;i<n;++i)
            cin>>a[i]>>b[i]>>c[i];
        double l = 0, r = 1000;
        while(r-l > eps){
            double lmid = l+(r-l)/3, rmid = r-(r-l)/3;
            if(maxmum(lmid) > maxmum(rmid)) l = lmid;
            else r = rmid;
        }
        cout<<fixed<<setprecision(4)<<maxmum(l)<<"\n";
    }
    return 0;
}
