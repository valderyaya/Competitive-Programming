#include<bits/stdc++.h>
// #include<ext/rope>
// using namespace __gnu_cxx;
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define REP1(i,a,b) for(int i=(a);i<=(b);i++)
#define pii pair<int,int>
typedef long long ll;
#define mkp make_pair
#define em emplace_back
#define F first
#define S second
#define ALL(x) (x).begin(),(x).end()
#define Rosario ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define pll pair<ll,ll>
//#define lb(x) (x&-x)

const double eps=1e-12;
typedef pair<double,double> pdd;
pdd operator+(pdd a,pdd b){return mkp(a.F+b.F,a.S+b.S);}
pdd operator-(pdd a,pdd b){return mkp(a.F-b.F,a.S-b.S);}
pdd operator*(pdd a,int n){return mkp(a.F*n,a.S*n);}
pdd operator/(pdd a,int n){return mkp(a.F/n,a.S/n);}
double dot(pdd a,pdd b){return a.F*b.F+a.S*b.S;}
double cross(pdd a,pdd b){return a.F*b.S-a.S*b.F;}
int ret(double x){
    if(fabs(x)<eps) return 0;
    return x<0?-1:1;
}
pdd get(double a,double b,double c,double d,double e,double f){return mkp((c*e-f*b)/(a*e-b*d),(c*d-f*a)/(b*d-e*a));}
// pdd get(pdd a,pdd b,pdd c){
//     if(ret(cross(b-a,c-a))==0){
//         if(dot(b-a,c-a)<eps) return a;
//         if(dot(a-b,c-b)<eps) return b;
//         if(dot(a-c,b-c)<eps) return c;
//     }
//     pdd mid1=(a+b)/2,mid2=(b+c)/2,cen;
//     double k1=-(a.S-b.S)/(a.F-b.F),k2=-(b.S-c.S)/(b.F-c.F);
//     cen.F=(mid2.S-mid1.S-k2*mid2.F+k1*mid1.F)/(k1-k2);
//     cen.S=k1*(cen.F-mid1.F)+mid1.S;
//     return cen;
// }
double dis(pdd x){return sqrt(dot(x,x));}
pdd a[1000005],c;
double r;
int n,m;
int main(){Rosario
    while(cin>>m>>n){
        if(n==0&&m==0) break;
    REP(i,n) cin>>a[i].F>>a[i].S;
    random_shuffle(a,a+n);c=a[0],r=0;
    for(int i=1;i<n;i++)
        if(ret(dis(a[i]-c)-r)>0){
            c=a[i],r=0;
            for(int j=0;j<i;j++)
                if(ret(dis(a[j]-c)-r)>0){
                    c=(a[i]+a[j])/2.;
                    r=dis(c-a[i]);
                    for(int k=0;k<j;k++)
                        if(ret(dis(c-a[k])-r)>0){
                            c=get(a[j].F-a[i].F,a[j].S-a[i].S,(a[j].S*a[j].S+a[j].F*a[j].F-a[i].F*a[i].F-a[i].S*a[i].S)/2,
                                  a[k].F-a[i].F,a[k].S-a[i].S,(a[k].F*a[k].F+a[k].S*a[k].S-a[i].F*a[i].F-a[i].S*a[i].S)/2);
                            r=dis(c-a[i]);
                        }
                }
        }
    cout<<fixed<<setprecision(3)<<r<<"\n";}
    //cout<<fixed<<setprecision(10)<<r<<"\n"<<c.F<<' '<<c.S<<"\n";
//    system("pause");
    return 0;
}
