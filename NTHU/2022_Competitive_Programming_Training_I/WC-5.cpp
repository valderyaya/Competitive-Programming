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
 
int n,m,bit[1001][1001];
string s[1001];
void add(int x,int y,int v){
	for(;x<=n;x+=lb(x))
		for(int i=y;i<=n;i+=lb(i))
			bit[x][i]+=v;
}
int qry(int x,int y){
	int res=0;
	for(;x;x-=lb(x))
		for(int i=y;i;i-=lb(i)) res+=bit[x][i];
	return res;
}
signed main(){Aincrad
	cin>>n>>m;
	REP1(i,1,n){
		cin>>s[i];
		REP1(j,1,n) if(s[i][j-1]=='*') add(i,j,1);
	}
	//REP1(i,1,n) REP1(j,1,n) cout<<qry(i,j)<<" \n"[j==n];
	for(int op,x,y,xx,yy;m--;){
		cin>>op>>x>>y;
		if(op==1){
			if(s[x][y-1]=='.') s[x][y-1]='*',add(x,y,1);
			else s[x][y-1]='.',add(x,y,-1);
		}else{
			cin>>xx>>yy;
			cout<<qry(xx,yy)-qry(x-1,yy)-qry(xx,y-1)+qry(x-1,y-1)<<"\n";
		}
	}
	return 0;
}
