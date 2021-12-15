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


int ret,n,m,k,a[1001][1001];
signed main(){Aincrad
	cin>>n>>m>>k;
	REP1(i,1,n) REP1(j,1,m) cin>>a[i][j],a[i][j]+=a[i-1][j];
	REP1(i,1,n) {
		REP1(j,i,n){
			int l=1,r=1,sum=0;
			for(;r<=m;++r){
				sum+=a[j][r]-a[i-1][r];
				while(sum>k) sum-=(a[j][l]-a[i-1][l]),l++;
				ret=max(ret,(j-i+1)*(r-l+1));
			}
		}
	}
	cout<<ret<<"\n";
	return 0;
}
