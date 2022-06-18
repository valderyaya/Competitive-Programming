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

int n,f[255][255];
char c;
map<int,int> mp;
signed main(){//Rosario
	cin>>n; getchar();
	REP1(i,1,n) REP1(j,1,n){
		cin>>c;
		if(c=='1'){
			f[i][j]=min({f[i][j-1],f[i-1][j-1],f[i-1][j]})+1;
			for(int k=f[i][j];k>1;--k) mp[k]++;
		}
	}
	for(auto &i:mp) cout<<i.F<<' '<<i.S<<"\n";
	return 0;
}
