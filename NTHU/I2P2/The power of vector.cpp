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
#define Aincrad ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define lb(x) (x&-x)

vector<pii> v;
struct p{
	int x,y,z;
	bool operator<(const p &a)const{return x!=a.x?x<a.x:y<a.y;}
};
struct q{
	int x,y,z;
	bool operator<(const q &a)const{return x!=a.x?x>a.x:y>a.y;}
};
priority_queue<q> mn;
priority_queue<p> mx;
string s;
bitset<200005> vis;
int n,x,cnt;
signed main(){Aincrad
	cin>>n;
	while(n--){
		cin>>s;
		if(s[1]=='a'){
			while(!mx.empty()&&vis[mx.top().z]) mx.pop();
			if(mx.empty()) continue; 
			cout<<mx.top().x<<' '<<mx.top().y<<"\n";
		}else if(s[0]=='f'){
			cin>>x;
			if(x>v.size()) continue;
			cout<<v[x-1].F<<"\n";
		}else if(s[1]=='i'){
			while(!mn.empty()&&vis[mn.top().z]) mn.pop();
			if(mn.empty()) continue;
			cout<<mn.top().x<<' '<<mn.top().y<<"\n";
		}else if(s[1]=='o'){
			if(v.empty()) continue;
			vis[v.back().S]=1;
			v.pop_back();
		}else{
			cin>>x;
			v.em(x,++cnt);
			mn.emplace(q{x,v.size(),cnt});
			mx.emplace(p{x,v.size(),cnt});
		}
	}
}
