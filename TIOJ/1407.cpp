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

int t,n,f[1000005];
vector<pii> v;
int main(){Rosario
	cin>>n;
	for(int w,m,c;n;--n){
		cin>>w>>m>>c;
		for(int j=1;j<=c;c-=j,j<<=1) v.em(mkp(w*j,m*j));
		if(c) v.em(mkp(w*c,m*c));
	}
	cin>>t;
	for(auto &i:v)
		for(int j=t;j>=i.F;--j) f[j]=max(f[j],f[j-i.F]+i.S);
	cout<<f[t]<<"\n";
	return 0;
}
