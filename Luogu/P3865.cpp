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

const int z=1e5+1;
int n,m,mx[z][18];
void build(){
	for(int j=1;j<18;++j)
		for(int i=1;i+(1<<j)-1<=n;++i)
			mx[i][j]=max(mx[i][j-1],mx[i+(1<<(j-1))][j-1]);
}
int main(){Rosario
	cin>>n>>m;
	REP1(i,1,n) cin>>mx[i][0];
	build();
	for(int x,y,l;m;--m){
		cin>>x>>y;
		l=__lg(y-x+1);
		cout<<max(mx[x][l],mx[y-(1<<l)+1][l])<<"\n";
	}
	return 0;
}
