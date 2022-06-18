//#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
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

typedef pair<double,double> pdd;
const double eps=1e-12;
pdd operator-(pdd a,pdd b){return mkp(a.F-b.F,a.S-b.S);}
pdd operator+(pdd a,pdd b){return mkp(a.F+b.F,a.S+b.S);}
pdd operator*(pdd a,int n){return mkp(a.F*n,a.S*n);}
pdd operator/(pdd a,int n){return mkp(a.F/n,a.S/n);}
double dot(pdd a,pdd b){return a.F*b.F+a.S*b.S;}
double cross(pdd a,pdd b){return a.F*b.S-a.S*b.F;}
double dis(pdd x){return sqrt(dot(x,x));}
pdd get(double a,double b,double c,double d,double e,double f){
    return mkp((e*c-b*f)/(a*e-b*d),(a*f-c*d)/(a*e-b*d));
}
int ret(double x){
    if(fabs(x)<eps) return 0;
    return x<0?-1:1;
}
pdd p[1000005],c;
int n;
double r;
int main(){Rosario
    cin>>n;
    REP(i,n) cin>>p[i].F>>p[i].S;
    random_shuffle(p,p+n);
    c=p[0],r=0;
    for(int i=1;i<n;i++)
        if(ret(dis(c-p[i])-r)>0){
            c=p[i],r=0;
            for(int j=0;j<i;j++)
                if(ret(dis(c-p[j])-r)>0){
                    c=(p[i]+p[j])/2;
                    r=dis(p[i]-c);
                    for(int k=0;k<j;k++)
                        if(ret(dis(c-p[k])-r)>0){
                            c=get(p[j].F-p[i].F,p[j].S-p[i].S,(p[j].F*p[j].F+p[j].S*p[j].S-p[i].F*p[i].F-p[i].S*p[i].S)/2,
                                  p[k].F-p[i].F,p[k].S-p[i].S,(p[k].F*p[k].F+p[k].S*p[k].S-p[i].F*p[i].F-p[i].S*p[i].S)/2);
                            r=dis(c-p[i]);
                        }
                }
        }
    cout<<fixed<<setprecision(10)<<r<<"\n"<<c.F<<' '<<c.S;
//    system("pause");
    return 0;
}
