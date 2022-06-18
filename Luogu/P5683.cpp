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

int ans=1e9,n,m,d1[3005],d2[3005],d3[3005],t1,t2,s1,s2;
vector<int> v[3005];
queue<int> q;
bitset<3005> vis;
void bfs(int st,int *d){
	REP1(i,1,n) d[i]=1e9;
	vis.reset(); vis[st]=1;
	d[st]=0; q.emplace(st); 
	while(!q.empty()){
		int x=q.front(); q.pop(); vis[x]=1;
		for(auto &i:v[x]) if(!vis[i]&&d[i]>d[x]+1) d[i]=d[x]+1,q.emplace(i);
	}
}
signed main(){Rosario
	cin>>n>>m;
	for(int x,y,i=0;i<m;++i) cin>>x>>y,v[x].em(y),v[y].em(x);
	cin>>s1>>t1>>s2>>t2;
	bfs(1,d1); bfs(s1,d2); bfs(s2,d3);
	// REP1(i,1,n) cout<<d1[i]<<" \n"[i==n];
	// REP1(i,1,n) cout<<d2[i]<<" \n"[i==n];
	// REP1(i,1,n) cout<<d3[i]<<" \n"[i==n];
	REP1(i,1,n) if(d1[i]+d2[i]<=t1&&d1[i]+d3[i]<=t2) ans=min(ans,d1[i]+d2[i]+d3[i]);
	cout<<(ans==1e9?-1:m-ans)<<"\n";
	return 0;
}
