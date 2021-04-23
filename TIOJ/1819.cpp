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

int n,m,a,b,mx;
set<int> s;
int main(){Rosario
	cin>>n>>m;
	while(n--){
		cin>>a>>b;
		if(a>b) swap(a,b);
		if(s.count(a)) s.erase(a);
		else s.insert(a);
		if(s.count(b+1)) s.erase(b+1);
		else s.insert(b+1);
		mx=max(mx,(int)s.size()/2);
	}cout<<mx<<"\n";
	return 0;
}
