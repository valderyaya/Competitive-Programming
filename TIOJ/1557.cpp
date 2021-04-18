//#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#include<bits/stdc++.h>
//#include<bits/extc++.h>
//using namespace __gnu_pbds;
using namespace std;
#define F first
#define S second
typedef long long ll;
#define REP(i,n) for(int i=0;i<(n);++i)
#define REP1(i,a,b) for(int i=(a);i<=(b);++i)
#define em emplace_back
#define mkp make_pair
#define ALL(x) (x).begin(),(x).end()
#define pii pair<int,int>
#define pll pair<ll,ll>
#define Rosario ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//#define lb(x) (x&-x)

const int z=10005,mod=1073741824;
struct edge{int to,nxt;}e[100005];
int n,m,ct[z],h[z],cnt=0,in[z];
void add(int u,int v){
	e[++cnt]=edge{v,h[u]};
	h[u]=cnt;
}
int solve(int st,int ed){
	queue<int> q;
	REP1(i,1,n) if(!in[i]) q.emplace(i);
	ct[st]=1; int x;
	while(!q.empty()){
		x=q.front(); q.pop();
		for(int i=h[x];i;i=e[i].nxt){
			int v=e[i].to;
			ct[v]=(ct[v]+ct[x])%mod;
			if(--in[v]==0) q.emplace(v);
		}
	}
	return ct[ed]%mod;
}
int main(){Rosario
	cin>>n>>m;
	int x,y;
	while(m--)cin>>x>>y,add(x,y),++in[y];
	cin>>x>>y;
	cout<<solve(x,y)<<"\n";
	return 0;
}
