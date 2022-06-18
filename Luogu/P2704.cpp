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

int f[3][1025][1025],ans,n,m,a[101],sum[1025];
int que(int x){
	int res=0;
	for(;x;x>>=1) if(x&1) ++res;
	return res;
}
vector<int> v;
int main(){Rosario
	cin>>n>>m;
	REP(i,n){
		char c;
		REP(j,m) cin>>c,a[i]<<=1,a[i]|=(c=='H'?1:0);
	}
	REP(i,(1<<m))
		if(!(i&(i<<1)||i&(i<<2))){
			v.em(i);
			sum[i]=que(i);
		}
	for(auto &i:v) if(!(i&a[0]))f[0][i][0]=sum[i];
	for(auto &i:v) for(auto &j:v) if(!(i&j||(i&a[0])||(j&a[1]))) f[1][i][j]=sum[i]+sum[j];
	REP1(i,2,n-1)
		for(auto &j:v){
			if(j&a[i-1]) continue;
			for(auto &k:v){
				if(j&k||a[i]&k) continue;
				for(auto &p:v){
					if(p&j||p&k||p&a[i-2]) continue;
					f[i%3][j][k]=max(f[i%3][j][k],f[(i-1)%3][p][j]+sum[k]);
				}
			}
		}
	for(auto &i:v) for(auto &j:v) ans=max(ans,f[(n-1)%3][i][j]);
	cout<<ans;
	return 0;
}
