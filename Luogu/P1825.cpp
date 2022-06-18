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

int n,m,sx,sy,cnt,dx[]={1,0,0,-1},dy[]={0,1,-1,0};
char a[305][305];
bool vis[305][305];
struct qwq{int x,y,c;};
void goto_(int &x,int &y){
	REP1(i,1,n) REP1(j,1,m)
		if((i!=x||j!=y)&&a[i][j]==a[x][y]){
			x=i,y=j; return;
		}
}
bool out(int x,int y){
	return x<1||x>n||y<1||y>m||vis[x][y]||a[x][y]=='#';
}
int bfs(){
	int x,y;
	queue<qwq> q; q.emplace(qwq{sx,sy,0});
	while(!q.empty()){
		qwq w=q.front(); q.pop();
		if(a[w.x][w.y]=='=') return w.c;
		if(isalpha(a[w.x][w.y])) goto_(w.x,w.y);
		REP(i,4){
			x=w.x+dx[i],y=w.y+dy[i];
			if(out(x,y)) continue;
			vis[x][y]=1; q.emplace(qwq{x,y,w.c+1});
		}
	}
}
int main(){Rosario
	cin>>n>>m;
	REP1(i,1,n) REP1(j,1,m) {
		cin>>a[i][j];
		if(a[i][j]=='@') sx=i,sy=j;
	}
	cout<<bfs()<<"\n";
	return 0;
}
