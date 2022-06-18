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

struct qwq{
	int id,val;
	bool operator<(const qwq &x)const{return val==x.val?id<x.id:val>x.val;}
}a[5005];
int n,m;
vector<qwq> ans;
int main(){Rosario
	cin>>n>>m;
	REP1(i,1,n) cin>>a[i].id>>a[i].val;
	sort(a+1,a+1+n);
	REP1(i,1,n){
		if(i<(m*3/2)) ans.em(a[i]);
		else if(i==(m*3/2)){
			ans.em(a[i]);
			for(int j=i+1;j<=n&&a[j].val==a[i].val;++j) ans.em(a[j]);
		}else break;
	}
	cout<<ans.back().val<<' '<<ans.size()<<"\n";
	for(auto &i:ans) cout<<i.id<<' '<<i.val<<"\n";
	return 0;
}
