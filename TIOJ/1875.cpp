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

ll n;
ll cal(ll x){
	ll ans=x;
	for(ll i=2;i*i<=x;++i){
		if(x%i==0){
			ans=ans/i*(i-1);
			while(x%i==0) x/=i;
		}
	}
	if(x>1) ans=ans/x*(x-1);
	return ans;
}
int main(){Rosario
	while(cin>>n){
		if(n<=600000000) cout<<cal(n)<<"\n";
		else cout<<n-1<<"\n";
	}
	return 0;
}
