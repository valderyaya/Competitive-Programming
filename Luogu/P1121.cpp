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

const int z=2e5+5;
int a[z<<1],n;
deque<pll> dq;
ll que(ll l,ll r,ll &ql,ll &qr){
	dq.clear(); ll s=0,mx=-1e18; dq.push_back(mkp(l-1,0ll));
	REP1(i,l,r){
		s+=a[i];
		while(!dq.empty()&&i-dq.front().F>n) dq.pop_front();
		if(!dq.empty()){
			ll x=s-dq.front().S;
			if(x>mx) mx=x,ql=dq.front().F+1,qr=i;
		}
		while(!dq.empty()&&s<=dq.back().S) dq.pop_back();
		dq.push_back(mkp(i,s));
	}return mx;
}
int main(){Rosario
	cin>>n;
	ll ql,qr,lp,rr,ans,x,y;
	REP1(i,1,n) cin>>a[i],a[i+n]=a[i];
	ans=que(1,n*2,ql,qr);
	if(ans<0){
		sort(a+1,a+1+n);
		cout<<a[n]+a[n-1];
		return 0;
	}
	x=que(qr+1,ql+n-1,lp,rr);
	REP1(i,ql,qr) a[i]=-a[i];
	y=que(ql,qr,lp,rr);
	cout<<max({0ll,x,y})+ans;
	return 0;
}
