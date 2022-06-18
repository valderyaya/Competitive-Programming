//#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#include<bits/stdc++.h>
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

typedef pair<double,double> pdd;
pdd a[200005],tmp[200005];
bool cmp(pdd x,pdd y){return x.F==y.F?x.S<y.S:x.F<y.F;}
bool cmp2(pdd x,pdd y){return x.S<y.S;}
double dis(pdd x,pdd y){
    double p=x.F-y.F,q=x.S-y.S;
    return sqrt(p*p+q*q);
}
double merge(int l,int r){
    if(l==r) return (double)1e10;
    if(l+1==r) return dis(a[l],a[r]);
    int k=0,mid=l+r>>1; double mn=min(merge(l,mid),merge(mid+1,r));
    REP1(i,l,r) if(fabs(a[i].F-a[mid].F)<mn) tmp[k++]=a[i];
    sort(tmp,tmp+k,cmp2);
    REP(i,k) for(int j=i+1;j<k&&fabs(tmp[i].S-tmp[j].S)<mn;j++) mn=min(mn,dis(tmp[i],tmp[j]));
    return mn; 
}
int n;
int main(){Rosario
    cin>>n;
    REP(i,n) cin>>a[i].F>>a[i].S;
    sort(a,a+n,cmp);
    cout<<fixed<<setprecision(4)<<merge(0,n-1)<<"\n";
    return 0;
}
