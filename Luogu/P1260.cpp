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

const int z=5005;
int n,m,d[z],cnt[z];
vector<pii> v[z];
bitset<z> vis;
queue<int> q;
bool spfa(){
	REP1(i,1,n) d[i]=1e9;
	q.emplace(0); vis[0]=1; cnt[0]=1;
	while(!q.empty()){
		int x=q.front(); q.pop(); vis[x]=0;
		for(auto &i:v[x]){
			if(d[i.F]>d[x]+i.S){
				d[i.F]=d[x]+i.S;
				if(++cnt[i.F]>n) return 1;
				if(!vis[i.F]) q.emplace(i.F),vis[i.F]=1;
			}
		}
	}
	return 0;
}
int main(){Rosario
	cin>>n>>m;
	REP1(i,1,n) v[0].em(i,0);
	for(int x,y,c;m;--m) cin>>x>>y>>c,v[y].em(x,c);
	if(spfa()) cout<<"NO SOLUTION";
	else{
		int add=0;
		REP1(i,1,n) add=min(add,d[i]);
		REP1(i,1,n) cout<<d[i]-add<<"\n";
	}
	return 0;
}
