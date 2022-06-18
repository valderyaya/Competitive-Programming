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

int n;
double a[15],l,r;
const double eps=1e-9;
double cal(double x){
	double res=0,now=1;
	for(int i=n;i>=0;--i,now*=x) res+=now*a[i];
	return res; 
}
void solve(){
	r+=1; double ml,mr;
	while(r-l>eps){
		ml=(l+l+r)/3,mr=(l+r+r)/3;
		if(cal(ml)<cal(mr)) l=ml;
		else r=mr;
	}
}
int main(){Rosario
	cin>>n>>l>>r;
	REP1(i,0,n) cin>>a[i];
	solve();
	cout<<fixed<<setprecision(5)<<l<<"\n";
	return 0;
}
