//#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#include<bits/stdc++.h>
//#include<bits/extc++.h>
//using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
#define F first
#define S second
#define REP(i,n) for(register int i=0;i<(n);++i)
#define REP1(i,a,b) for(register int i=(a);i<=(b);++i)
#define em emplace_back
#define ALL(x) (x).begin(),(x).end()
#define mkp make_pair
#define pii pair<int,int>
#define pll pair<ll,ll>
#define Rosario ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define lb(x) (x&-x)
//#define line cout<<"-------------------------\n";

const double eps=1e-8;
struct qq{double a,b,c;}q[10005];
int n;
double cal(double x){
	double res=1e18;
	for(int i=0;i<n;++i) res=min(res,(q[i].a*x*x+q[i].b*x+q[i].c));
	return res;
}
int main(){Rosario
    cin>>n;
	for(int i=0;i<n;++i) cin>>q[i].a>>q[i].b>>q[i].c;
	double l=0,r=129600,ml,mr;
	while(r-l>eps){
		ml=(l+l+r)/3,mr=(l+r+r)/3;
		if(cal(mr)<cal(ml)) r=mr;
		else l=ml;
	}
	cout<<fixed<<setprecision(6)<<l<<"\n";
    return 0;
}
