//#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#include<bits/stdc++.h>
//#include<bits/extc++.h>
//using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
#define F first
#define S second
#define REP(i,n) for(register int i=0;i<(n);++i)
#define REP1(i,a,b) for(register int i=(a);i<=(b);++i)
#define em emplace_back
#define ALL(x) (x).begin(),(x).end()
#define mkp make_pair
#define pii pair<int,int>
#define pll pair<ll,ll>
#define Rosario ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define lb(x) (x&-x)
//#define line cout<<"-------------------------\n";

int b[101][301][301],n,m,a[301][301];
void add(int c,int x,int y,int v){
	for(;x<=n;x+=lb(x))
		for(int i=y;i<=m;i+=lb(i)) b[c][x][i]+=v;
}
int que(int c,int x,int y){
	int res=0;
	for(;x;x-=lb(x))
		for(int i=y;i;i-=lb(i)) res+=b[c][x][i];
	return res;
}
int main(){Rosario
    cin>>n>>m;
	int q,x1,x2,y1,y2,k,c;
	REP1(i,1,n) REP1(j,1,m) cin>>c,add(c,i,j,1),a[i][j]=c;
	cin>>q;
	while(q--){
		cin>>k;
		if(k==1) cin>>x1>>y1>>c,add(a[x1][y1],x1,y1,-1),add(a[x1][y1]=c,x1,y1,1);
		else cin>>x1>>x2>>y1>>y2>>c,cout<<que(c,x2,y2)-que(c,x2,y1-1)-que(c,x1-1,y2)+que(c,x1-1,y1-1)<<"\n";
	}
    return 0;
}
