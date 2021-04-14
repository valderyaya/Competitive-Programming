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

const int z=1e3+5;
ll ans;
int a[z][z],n,m,dx[]={0,1,0,-1},dy[]={1,0,-1,0};
struct qwq{
	int w,x,y;
	bool operator<(const qwq &_)const{return w<_.w;}
};
bool vis[z][z];
priority_queue<qwq> q;
int main(){Rosario
	cin>>n>>m;
	int x,y;
	REP1(i,1,n) REP1(j,1,m) cin>>a[i][j],q.emplace(qwq{a[i][j],i,j}),ans+=a[i][j];
	while(!q.empty()){
		qwq t=q.top(); q.pop();
		REP(i,4){
			x=t.x+dx[i],y=t.y+dy[i];
			if(vis[x][y]) ans+=a[x][y];
		}
		vis[t.x][t.y]=1;
	}cout<<ans;
	return 0;
}
