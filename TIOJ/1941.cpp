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


int n,b[800005]={};
set<int> s;
void add(int x,int v){
	for(;x;x-=lb(x)) b[x]+=v;
}
void mdy(int l,int r,int v){
	add(l,-v);
	add(r,v);
}
int que(int x){
	int res=0;
	for(;x<=n;x+=lb(x)) res+=b[x];
	return res;
}
int main(){Rosario
	cin>>n;
	int l,r;
	s.insert(n);
	REP(i,n){
		cin>>l>>r;
		s.insert(l);
		auto it=s.upper_bound(r);
		mdy(l,*it,1);
		int now=que(*it);
		for(;it!=prev(s.end());it=s.erase(it)){
			int x=que(*it+1);
			if(x>now) break;
			mdy(*it,*next(it),now-x);
		}
	}cout<<que(n)<<"\n";
	return 0;
}
