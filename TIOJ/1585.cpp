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

int n,m[128];
bool cmp(string a,string b){
	REP(i,min(a.size(),b.size()))
		if(a[i]!=b[i]) return m[a[i]]<m[b[i]];
	return a.size()<b.size();
}
string s[1005];
int main(){Rosario
	for(int i='a',j=1;i<='m';++i,j+=2) m[i]=j;
	for(int i='z',j=2;i>='n';--i,j+=2) m[i]=j;
	cin>>n;
	REP(i,n) cin>>s[i];
	sort(s,s+n,cmp);
	REP(i,n) cout<<s[i]<<"\n";
	return 0;
}
