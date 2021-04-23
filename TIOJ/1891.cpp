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

const ll mod=20190823,base=1000019;
ll v[500005],n,m;
ll hash_(ll x,ll y){return (x*base+y)%mod;}
int main(){Rosario
	cin>>n>>m;
	int op,x,y,k;
	while(m--){
		cin>>op;
		if(op<2){
			cin>>x>>y;
			if(x>y) swap(x,y);
			ll hs=hash_(x,y);
			if(op==0) v[x]=(v[x]+hs)%mod,v[y]=(v[y]-hs)%mod;
			else v[x]=(v[x]-hs)%mod,v[y]=(v[y]+hs)%mod;
		}else{
			cin>>k; y=0;
			while(k--) cin>>x,y=(y+v[x])%mod;
			cout<<(y==0)<<"\n";
		}
	}
	return 0;
}
