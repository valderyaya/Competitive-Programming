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


int n,val[100005],cnt,tr[3200005][2],ans;
vector<pii> v[100005];
void dfs(int x,int p){
	for(auto &i:v[x])
		if(i.F!=p) val[i.F]=val[x]^i.S,dfs(i.F,x);
}
void ins(int x){
	int p=0,c;
	for(int i=31;~i;--i){
		c=(x>>i&1);
		if(!tr[p][c]) tr[p][c]=++cnt;
		p=tr[p][c];
	}
}
int que(int x){
	int res=0,p=0,c;
	for(int i=31;~i;--i){
		c=(x>>i&1);
		if(tr[p][!c]) res|=(1<<i),p=tr[p][!c];
		else p=tr[p][c];
	}
	return res;
}
int main(){Rosario
	cin>>n;
	for(int x,y,z,i=1;i<n;++i) cin>>x>>y>>z,v[x].em(y,z),v[y].em(x,z);
	dfs(1,1);
	REP1(i,1,n) ins(val[i]);
	REP1(i,1,n) ans=max(ans,que(val[i]));
	cout<<ans;
	return 0;
}
