//#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#include<bits/extc++.h>
//using namespace __gnu_pbds;
typedef long long ll;
using namespace std;
#define REP(i,n) for (int i=0;i<(n);i++)
#define REP1(i,a,b) for(int i=(a);i<=(b);i++)
#define em emplace_back
#define ALL(x) (x).begin(),(x).end()
#define F first
#define S second
#define mkp make_pair
#define pii pair<int,int>
#define Rosario ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define pll pair<ll,ll> 
//#define lb(x) (x&-x)
#define line cout<<"-------------------------------\n";

typedef pair<double,double> pdd;
pdd p[50005],tmp[50005];
int n;
bool cmp(pdd a,pdd b){return a.F==b.F?a.S<b.S:a.F<b.F;}
bool cmp2(pdd a,pdd b){return a.S<b.S;}
double dis(pdd a,pdd b){
    double x=a.F-b.F,y=a.S-b.S;
    return sqrt(x*x+y*y);
}
double merge(int l,int r){
    if(l==r) return (double) 1e12;
    if(l+1==r) return dis(p[l],p[r]);
    int i,j,k=0,m=l+r>>1;
    double d=min(merge(l,m),merge(m+1,r)),dd;
    for(i=l;i<=r;i++) if(fabs(p[i].F-p[m].F)<=d) tmp[k++]=p[i];
    sort(tmp,tmp+k,cmp2);
    for(i=0;i<k;i++)
        for(j=i+1;j<k&&tmp[j].S-tmp[i].S<d;j++){
            dd=dis(tmp[i],tmp[j]);
            d=min(dd,d);
        }
    return d;
}
int main(){Rosario
    while(cin>>n){
        REP(i,n) cin>>p[i].F>>p[i].S;
        sort(p,p+n,cmp);
        cout<<fixed<<setprecision(6)<<merge(0,n-1)<<"\n";
    }
//    system("pause");
    return 0;
}
