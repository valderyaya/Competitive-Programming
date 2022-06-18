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

ll ans,f[10][100][2000],n,k,cnt[2000];
vector<ll> v;
int main(){Rosario
	cin>>n>>k;
	for(int i=0;i<(1<<n);++i){
		if((i&((i<<1)|(i>>1)))==0) v.pb(i);
		for(int j=0;j<11;++j) if(i>>j&1) ++cnt[i];
	}
	f[0][0][0]=1;
	REP1(i,1,n) for(auto &j:v) for(auto &p:v)
		if(((p|(p<<1)|(p>>1))&j)==0)
			REP1(l,0,k) if(l>=cnt[j]) f[i][l][j]+=f[i-1][l-cnt[j]][p];
	for(auto &i:v) ans+=f[n][k][i];
	cout<<ans;
	return 0;
}
