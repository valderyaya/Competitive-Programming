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

ll f[100005],ans;
int n,m;
int main(){Rosario
	cin>>n>>m;
	if(n>m) swap(n,m);
	for(int i=n;i;--i){
		f[i]=(ll)(n/i)*(m/i);
		for(int j=i<<1;j<=n;j+=i) f[i]-=f[j];
		ans+=f[i]*(i*2-1);
	}cout<<ans;
	return 0;
}
