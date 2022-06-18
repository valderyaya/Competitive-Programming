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

const int z=155;
int n,m,ans=1e9,f[z][z];
vector<int> v[z];
int dfs(int x){
	int s=1;
	for(auto &i:v[x]){
		s+=dfs(i);
		for(int j=s;j;--j)
			for(int k=1;k<j;++k) f[x][j]=min(f[x][j],f[x][j-k]+f[i][k]-1);
	}return s;
}
int main(){Rosario
	cin>>n>>m;
	memset(f,64,sizeof(f));
	REP1(i,1,n) f[i][1]=0;
	for(int x,y,i=1;i<n;++i) cin>>x>>y,v[x].em(y),f[x][1]++;
	dfs(1); ans=f[1][m];
	REP1(i,1,n) if(ans>f[i][m]) ans=f[i][m]+1;
	cout<<ans;
	return 0;
}
