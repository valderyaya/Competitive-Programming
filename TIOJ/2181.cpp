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

int n,m,f[1005],mx;
int main(){Rosario
	cin>>n>>m;
	for(int x,y;m;--m){
		cin>>x>>y;
		for(int i=n;i>=y;--i) mx=max(mx,f[i]=max(f[i],f[i-y]+x));
	}
	if(mx==0) return cout<<"0 0",0;
	REP1(i,1,n) if(f[i]==mx) return cout<<mx<<' '<<i,0;
	return 0;
}
