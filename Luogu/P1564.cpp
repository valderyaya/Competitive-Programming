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

int n,m,s[2505],f[2505];
int main(){Rosario
	cin>>n>>m;
	REP1(i,1,n){
		cin>>s[i];
		s[i]=(s[i]==1?1:-1);
		s[i]+=s[i-1];
		f[i]=1e9;
	}
	REP1(i,1,n) REP1(j,1,i) if(abs(s[i]-s[j-1])==i-j+1||abs(s[i]-s[j-1])<=m) f[i]=min(f[i],f[j-1]+1);
	cout<<f[n];
	return 0;
}
