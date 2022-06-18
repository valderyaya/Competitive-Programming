#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define F first
#define S second
#define REP(i,n) for(int i=0;i<(n);i++)
#define REP1(i,a,b) for(int i=(a);i<=(b);i++)
#define em emplace_back
#define ALL(x) (x).begin(),(x).end()
#define mkp make_pair
#define pii pair<int,int>
#define pll pair<ll,ll>
#define Rosario ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//#define lb(x) (x&-x)

typedef pair<double,double> pdd;
double eps=1e-12;
pdd operator+(const pdd &a,const pdd &b){return mkp(a.F+b.F,a.S+b.S);}
pdd operator-(const pdd &a,const pdd &b){return mkp(a.F-b.F,a.S-b.S);}
pdd operator*(const pdd &a,const int x){return mkp(a.F*x,a.S*x);}
pdd operator/(const pdd &a,const int x){return mkp(a.F/x,a.S/x);}
double dot(const pdd &a,const pdd &b){return a.F*b.F+a.S*b.S;}
double cross(const pdd &a,const pdd &b){return a.F*b.S-a.S*b.F;}
int ori(const pdd &a,const pdd &b,const pdd &c){
    double x=cross(b-a,c-a);
    if(fabs(x)<0) return 0;
    return x>0?1:-1;
}
bool cmp(const pdd &a,const pdd &b){return a.F==b.F?a.S<b.S:a.F<b.F;}
double ret(const pdd &a,const pdd &b){
    double x=a.F-b.F,y=a.S-b.S;
    return sqrt(x*x+y*y);
}
int n,idx1=0,idx2;
pdd a[10005],st[10005];
int main(){Rosario
    cin>>n;
    REP(i,n) cin>>a[i].F>>a[i].S;
    sort(a,a+n,cmp);
    REP(i,n){
        while(idx1>1){
            pdd x=st[idx1-2],y=st[idx1-1];
            if(ori(x,y,a[i])>0) break;
            else idx1--;
        }st[idx1++]=a[i];
    }idx2=idx1;
    for(int i=n-1;i>=0;i--){
        while(idx2-idx1>1){
            pdd x=st[idx2-2],y=st[idx2-1];
            if(ori(x,y,a[i])>0) break;
            else idx2--; 
        }st[idx2++]=a[i];
    }
    double sum=0;
    for(int i=0;i<idx2-1;i++) sum+=ret(st[i],st[i+1]);
    cout<<fixed<<setprecision(2)<<sum<<"\n";
//    system("pause");
    return 0;
}
