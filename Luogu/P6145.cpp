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
#define lb(x) (x&-x)

ll n,m,s,d[100005];
vector<pii> v[100005];
priority_queue<pii> q;
void dijk(){
	REP1(i,1,n) d[i]=-1e18;
	q.emplace(0,0); 
	while(!q.empty()){
		int x=q.top().F,y=q.top().S; q.pop(); 
		if(d[y]!=x) continue;
		for(auto &i:v[y]){
			if(d[i.F]<x+i.S){
				d[i.F]=x+i.S;
				q.emplace(d[i.F],i.F);
			}
		}
	}
}
int main(){Rosario
	cin>>n>>m>>s;
	for(int x,i=1;i<=n;++i) cin>>x,v[0].em(i,x);
	for(int x,y,c;s;--s){
		cin>>x>>y>>c;
		v[x].em(y,c);
	}
	dijk();
	REP1(i,1,n) cout<<d[i]<<"\n";
	return 0;
}
