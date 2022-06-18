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

int ans,cnt,n;
queue<pii> qe;
set<pii> s;
priority_queue<pii,vector<pii>,greater<pii>> q;
bool assign(int t,int m,int p){
	for(auto it=s.begin();it!=s.end();it++){
		auto x=next(it);
		if(x!=s.end()&&m<=x->F-(it->F+it->S)){
			s.insert({it->F+it->S,m});
			q.emplace(t+p,it->F+it->S);
			return 1;
		}
	}
	return 0;
}
void release(int t){
	while(!q.empty()&&q.top().F<=t){
		int x=q.top().F; ans=x;
		while(!q.empty()&&q.top().F==x){
			pii tmp=q.top(); q.pop();
			auto it=s.lower_bound({tmp.S,0});
			s.erase(it);
		}
		while(!qe.empty()){
			pii tmp=qe.front(); 
			if(assign(x,tmp.F,tmp.S)) qe.pop();
			else break;
		}
	}
}
signed main(){Rosario
	int t,m,p;
	cin>>n;
	s.insert({-1,1}); s.insert({n,1});
	while(cin>>t>>m>>p,t||m||p){
		release(t);
		if(!assign(t,m,p)) {
			qe.emplace(m,p);
			++cnt;
		}
	}
	release(1e9+5);
	cout<<ans<<'\n'<<cnt<<"\n";
	return 0;
}
