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

const int z=1e5+5;
int n,m,cnt,c[z],d[z];
vector<pii> v[z];
queue<int> q;
bitset<z> vis;
bool spfa(){
	q.emplace(0); vis[0]=1; c[0]=1;
	while(!q.empty()){
		int x=q.front(); q.pop();vis[x]=0;
		for(auto &i:v[x])
			if(d[i.F]<d[x]+i.S){
				d[i.F]=d[x]+i.S;
				if(!vis[i.F]) q.emplace(i.F),vis[i.F]=1;
				if(++c[i.F]>=n) return 0;
			}
	}
	return 1;
}
int main(){Rosario
	cin>>n>>m;
	REP1(i,1,n) v[0].pb({i,1});
	for(int x,a,b;m;--m){
		cin>>x>>a>>b;
		if(x==1) v[a].pb({b,0}),v[b].pb({a,0});
		else if(x==2){
			if(a==b) return cout<<"-1",0;
			v[a].pb({b,1});
		}
		else if(x==3) v[b].pb({a,0});
		else if(x==4) {
			if(a==b) return cout<<"-1",0;
			v[b].pb({a,1});
		}
		else v[a].pb({b,0});
	}
	if(spfa()){
		ll ans=0;
		REP1(i,1,n) ans+=d[i];
		cout<<ans;
	}else cout<<"-1";
	return 0;
}
