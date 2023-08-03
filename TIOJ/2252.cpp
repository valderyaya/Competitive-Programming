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


int n,xx,yy,X[101],Y[101];
double ans=1e9+8;
double dis(double x, double y, double x1, double y1, double x2, double y2){
    double c = (x2-x1)*(x-x1)+(y2-y1)*(y-y1);
    if(c<=0) return sqrt((x-x1)*(x-x1)+(y-y1)*(y-y1));
    double d2=(x2-x1)*(x2-x1)+(y2-y1)*(y2-y1);
    if(c>=d2) return sqrt((x-x2)*(x-x2)+(y-y2)*(y-y2));
    double r= c/d2;
    double px=x1+(x2-x1)*r;
    double py=y1+(y2-y1)*r;
    return sqrt((x-px)*(x-px)+(py-y)*(py-y));
}
signed main(){StarBurstStream
    cin>>xx>>yy>>n;
    REP(i,n+1) cin>>X[i]>>Y[i];
    for(int i=0;i<n;++i)
        ans= min(ans, dis(xx,yy,X[i],Y[i],X[i+1],Y[i+1]));
    cout<<fixed<<setprecision(8) <<ans<<"\n";
    return 0;
}
