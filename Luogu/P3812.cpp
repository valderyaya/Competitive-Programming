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
#define lb(x) (x&-x)

ll a[55],n,m;
void ins(ll x){
	for(ll i=50;~i;--i)
		if(x>>i&1){
			if(!a[i]) return a[i]=x,void();
			else x^=a[i];
		}
}
ll que(ll x=0){
	for(ll i=50;~i;--i)
		x=max(x,x^a[i]);
	return x;
}
int main(){Rosario
	cin>>n;
	for(ll x;n;--n) cin>>x,ins(x);
	cout<<que();
	return 0;
}
