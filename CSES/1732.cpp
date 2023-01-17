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
 
int f[1000005];
string s;
void dfs(int x){
	if(!x) return;
	dfs(f[x-1]);
	if(f[x-1]) cout<<f[x-1]<<' ';
}
signed main(){Aincrad
	cin>>s;
	for(int i=1;i<s.size();++i){
		int j=f[i-1];
		while(j&&s[j]!=s[i]) j=f[j-1];
		if(s[i]==s[j])++j;
		f[i]=j;
	}
	dfs(s.size());
	return 0;
}
