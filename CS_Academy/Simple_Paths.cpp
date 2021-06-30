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

int n,m,q,bel[1005],st,ed,cnt,fa[1005];
bitset<1005> vis,is[1005];
vector<int> v[1005];
void dfs(int x){
	vis[x]=1; bel[x]=cnt;
	for(auto &i:v[x]) if(!vis[i]) dfs(i); 
}
void dfs2(int x){
	vis[x]=1;
	for(auto &i:v[x]){
		if(vis[i]||(x==st&&i==ed)||(x==ed&&i==st)) continue;
		dfs2(i);
	}
}
bool ck(){
	queue<int> q;
	vis.reset(); vis[st]=1;
	q.emplace(st);
	while(!q.empty()){
		int x=q.front(); q.pop();
		for(auto &i:v[x]) if(!vis[i]) fa[i]=x,vis[i]=1,q.emplace(i);
	}
	for(int i=ed;i!=st;i=fa[i]) if(!is[i][fa[i]]) return 0;
	return 1;
}
int main(){Rosario
	cin>>n>>m>>q;
	while(m--) cin>>st>>ed,v[st].em(ed),v[ed].em(st);
	REP1(i,1,n) if(!vis[i]) ++cnt,dfs(i);
	REP1(i,1,n) for(auto &j:v[i]){
		st=i,ed=j; vis.reset(); int tmp=0;
		REP1(i,1,n) if(!vis[i]) ++tmp,dfs2(i);
		if(tmp>cnt) is[i][j]=1;
	}
	while(q--){
		cin>>st>>ed;
		if(bel[st]!=bel[ed]) cout<<"0\n";
		else cout<<ck()<<"\n";
	}
	return 0;
}
