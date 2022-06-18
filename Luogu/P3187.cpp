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

typedef pair<double,double> pdd;
const double eps=1e-12;
pdd operator-(pdd a,pdd b){return mkp(a.F-b.F,a.S-b.S);}
pdd operator+(pdd a,pdd b){return mkp(a.F+b.F,a.S+b.S);}
pdd operator*(pdd a,double n){return mkp(a.F*n,a.S*n);}
pdd operator/(pdd a,double n){return mkp(a.F/n,a.S/n);}
pdd rot(pdd x){return mkp(-x.S,x.F);}
double dot(pdd a,pdd b){return a.F*b.F+a.S*b.S;}
double cross(pdd a,pdd b){return a.F*b.S-a.S*b.F;}
int ret(double x){
    if(fabs(x)<eps) return 0;
    return x<0?-1:1;
}
double dis(pdd x){return sqrt(dot(x,x));}
int ori(pdd a,pdd b,pdd c){return ret(cross(b-a,c-a));}
pdd p[50005],c,st[50005],res[4];
double r;
int n,idx=0,idx2;
bool cmp(pdd a,pdd b){return ret(a.F-b.F)?a.S<b.S:a.F<b.F;}
void loli(){
    sort(p,p+n);
    REP(i,n){
        while(idx>1&&ori(st[idx-2],st[idx-1],p[i])<=0) idx--;
        st[idx++]=p[i];
    }idx2=idx;
    for(int i=n-1;i>0;i--){
        while(idx2>idx&&ori(st[idx2-2],st[idx2-1],p[i])<=0) idx2--;
        st[idx2++]=p[i];
    }st[idx2]=st[0];
}
void solve(){
    int le,ri=0,up=0;
    double r,l,h,d,mi=1e9,area;
    REP(i,idx2){
        while(ret(fabs(cross(st[i+1]-st[i],st[up]-st[i]))-fabs(cross(st[i+1]-st[i],st[up+1]-st[i])))<=0) up=(up+1)%idx2;
        while(ret(dot(st[i+1]-st[i],st[ri]-st[i])-dot(st[i+1]-st[i],st[ri+1]-st[i]))<=0) ri=(ri+1)%idx2;
        if(i==0) le=up;
        while(ret(dot(st[i+1]-st[i],st[le]-st[i])-dot(st[i+1]-st[i],st[le+1]-st[i]))>=0) le=(le+1)%idx2;
        d=dis(st[i+1]-st[i]);
        h=fabs(cross(st[i+1]-st[i],st[up]-st[i]))/d;
        r=fabs(dot(st[i+1]-st[i],st[ri]-st[i]))/d;
        l=fabs(dot(st[i+1]-st[i],st[le]-st[i]))/d;
        area=(l+r)*h;
        if(area<mi){
            mi=area;
            res[0]=st[i]+(st[i+1]-st[i])*(r/d);
            res[1]=res[0]+rot(st[i+1]-st[i])*(h/d);
            res[2]=res[1]+rot(res[1]-res[0])*((l+r)/h);
            res[3]=res[2]+(res[0]-res[1]);
        }
    }
    double x,y;
    int id=0;
    for(int i=1;i<4;i++) if(ret(res[i].S-res[id].S)<0||(ret(res[i].S-res[id].S)==0&&ret(res[i].F-res[id].F)<0)) id=i;
    cout<<fixed<<setprecision(5)<<mi<<"\n";
    REP(i,4){
        x=res[(id+i)%4].F,y=res[(id+i)%4].S;
        if(fabs(x)<eps) x=fabs(x);
        if(fabs(y)<eps) y=fabs(y);
        cout<<x<<' '<<y<<"\n";
    }
}
int main(){Rosario
    cin>>n;
    REP(i,n) cin>>p[i].F>>p[i].S;
    loli();solve();
//    system("pause");
    return 0;
}
