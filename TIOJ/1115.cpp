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


double x,y,r;
int main(){Rosario
	while(cin>>x>>y>>r){
		if(y<=-r) cout<<"0.00\n";
		else if(y>=r) cout<<fixed<<setprecision(2)<<r*r*acos(-1)<<"\n";
		else {
			double t1=acos(-y/r),t2=acos(y/r);
			cout<<fixed<<setprecision(2)<<r*r*t1+y*r*sin(t2)<<"\n";
		}
	}
	return 0;
}
