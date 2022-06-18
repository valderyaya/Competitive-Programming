#include<bits/stdc++.h>
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
const double eps=1e-12;
pdd operator-(pdd a,pdd b){return mkp(a.F-b.F,a.S-b.S);}
pdd operator+(pdd a,pdd b){return mkp(a.F+b.F,a.S+b.S);}
pdd operator*(pdd a,int n){return mkp(a.F*n,a.S*n);}
pdd operator/(pdd a,int n){return mkp(a.F/n,a.S/n);}
double dot(pdd a,pdd b){return a.F*b.F+a.S*b.S;}
double cross(pdd a,pdd b){return a.F*b.S-a.S*b.F;}
int ret(double x){
    if(fabs(x)<eps) return 0;
    return x<0?-1:1;
}
pdd get(double a,double b,double c,double d,double e,double f){
    return mkp((c*e-b*f)/(a*e-d*b),(a*f-d*c)/(a*e-b*d));
}
double dis(pdd x){return sqrt(dot(x,x));}
int n;
pdd p[1000005],c;
double r;
int main(){Rosario
    cin>>n;
    REP(i,n) cin>>p[i].F>>p[i].S;
    random_shuffle(p,p+n);
    c=p[0],r=0;
    for(int i=1;i<n;i++)
        if(ret(dis(p[i]-c)-r)>0){
            c=p[i],r=0;
            for(int j=0;j<i;j++)
                if(ret(dis(c-p[j])-r)>0){
                    c=(p[i]+p[j])/2.;
                    r=dis(c-p[i]);
                    for(int k=0;k<j;k++)
                        if(ret(dis(c-p[k])-r)>0){
                            double x=p[j].F-p[i].F,y=p[j].S-p[i].S,xx=p[k].F-p[i].F,yy=p[k].S-p[i].S;
                            c=get(x,y,(p[j].F*p[j].F+p[j].S*p[j].S-p[i].F*p[i].F-p[i].S*p[i].S)/2,
                                  xx,yy,(p[k].F*p[k].F+p[k].S*p[k].S-p[i].F*p[i].F-p[i].S*p[i].S)/2);
                            r=dis(c-p[i]);
                        }
                }
        }
    cout<<fixed<<setprecision(2)<<c.F<<' '<<c.S<<' '<<r<<"\n";
//    system("pause");
    return 0;
}
