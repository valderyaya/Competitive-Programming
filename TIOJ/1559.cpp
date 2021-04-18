//#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#include<bits/stdc++.h>
//#include<bits/extc++.h>
//using namespace __gnu_pbds;
using namespace std;
#define F first
#define S second
typedef long long ll;
#define REP(i,n) for(register int i=0;i<(n);++i)
#define REP1(i,a,b) for(register int i=(a);i<=(b);++i)
#define em emplace_back
#define mkp make_pair
#define pb push_back
#define ALL(x) (x).begin(),(x).end()
#define pii pair<int,int>
#define pll pair<ll,ll>
#define Rosario ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//#define lb(x) (x&-x)

typedef pair<double,double> pdd;
const double pi=3.14159265;
pdd operator+(pdd a,pdd b){return {a.F+b.F,a.S+b.S};}
pdd operator-(pdd a,pdd b){return {a.F-b.F,a.S-b.S};}
pdd cal(pdd x,double dg){
	dg=dg*pi/180;
	return {x.F*cos(dg)+x.S*sin(dg),-x.F*sin(dg)+x.S*cos(dg)};
}
pdd a,b;
int main(){Rosario
	while(cin>>a.F>>a.S>>b.F>>b.S){
		pdd x=cal(a-b,60)+b,y=cal(a-b,-60)+b;
		if(x.F<y.F||(x.F==y.F&&x.S<y.S)) cout<<fixed<<setprecision(3)<<x.F<<' '<<x.S<<' '<<y.F<<' '<<y.S<<"\n";
		else cout<<fixed<<setprecision(3)<<y.F<<' '<<y.S<<' '<<x.F<<' '<<x.S<<"\n";
	}
	return 0;
}
