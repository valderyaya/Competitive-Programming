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

int n,d;
struct qq{
	double l,r;
	bool operator<(const qq &x)const{return r<x.r;}
};
qq a[1005];
int main(){Rosario
	cin>>n>>d;
	int x,y;
	REP(i,n) {
		cin>>x>>y;
		a[i].l=x-sqrt(d*d-y*y);
		a[i].r=x+sqrt(d*d-y*y);
	}sort(a,a+n);
	int cnt=0;
	double r=-1e9;
	REP(i,n) if(r<a[i].l) ++cnt,r=a[i].r;
	cout<<cnt<<"\n";
	return 0;
}
