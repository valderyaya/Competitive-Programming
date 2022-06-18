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

const int z=3005;
int f[z][z],n,m;
vector<pii> v[z];
int dfs(int x){
	if(x>n-m) return 1;
	int s=0,t;
	for(auto &i:v[x]){
		t=dfs(i.F); s+=t;
		for(int j=s;j;--j)
			REP1(k,1,t) if(j-k>=0) f[x][j]=max(f[x][j],f[x][j-k]+f[i.F][k]-i.S);
	}return s;
}
int main(){Rosario
	cin>>n>>m;
	memset(f,-127,sizeof(f));
	REP1(i,1,n) f[i][0]=0;
	for(int x,y,k,i=1;i<=n-m;++i){
		cin>>k;
		while(k--) cin>>x>>y,v[i].em(x,y);
	}
	for(int i=n-m+1;i<=n;++i) cin>>f[i][1];
	dfs(1);
	for(int i=m;i;--i)
		if(f[1][i]>=0) return cout<<i,0;
	return 0;
}
