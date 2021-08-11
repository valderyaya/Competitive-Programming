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

double a,b,c,d;
double cal(double x){
    return x*x*x*a+b*x*x+c*x+d;
}
void solve(double l,double r){
    if(r-l<=0.001) return cout<<fixed<<setprecision(2)<<l<<' ',void();
    double mid=(l+r)/2;
    if(cal(mid)==0) cout<<fixed<<setprecision(2)<<mid<<' ',void();
    if(cal(r)==0) cout<<fixed<<setprecision(2)<<r<<' ',void();
    if(cal(mid)*cal(r)<0) solve(mid,r);
    else if(cal(l)*cal(mid)<0) solve(l,mid);
}
int main(){//Rosario
    cin>>a>>b>>c>>d;
    for(double i=-100;i<100;i++){
        if(cal(i)*cal(i+1.)<=0) solve(i,i+1.0);
    }
    return 0;
}
