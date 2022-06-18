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

string a[1501];
int n,m,vis[1501][1501][3],dx[]={1,0,0,-1},dy[]={0,1,-1,0};
bool flag;
void dfs(int x,int y,int px,int py){
	if(flag||a[x][y]=='#') return;
	if(vis[x][y][0]&&(vis[x][y][1]!=px||vis[x][y][2]!=py)) return flag=1,void();
	vis[x][y][0]=1,vis[x][y][1]=px,vis[x][y][2]=py;
	REP(i,4){
		int nx=(dx[i]+x+n)%n,ny=(dy[i]+y+m)%m;
		if(!vis[nx][ny][0]||vis[nx][ny][1]!=px+dx[i]||vis[nx][ny][2]!=py+dy[i]) dfs(nx,ny,px+dx[i],py+dy[i]);
	}
}
int main(){Rosario
	while(cin>>n>>m){
		memset(vis,0,sizeof(vis)); flag=0;
		REP(i,n) cin>>a[i];
		REP(i,n) REP(j,m) if(a[i][j]=='S') {dfs(i,j,i,j);break;}
		cout<<(flag?"Yes":"No")<<"\n";
	}
	return 0;
}
