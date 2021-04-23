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

const int z=1005;
int sx,sy,ex,ey,n,m,a[z][z],t,dx[]={1,0,0,-1},dy[]={0,1,-1,0};
queue<pii> q;
bool vis[z][z];
bool ck(int mid){
	while(!q.empty()) q.pop();
	memset(vis,0,sizeof(vis));
	q.emplace(sx,sy); vis[sx][sy]=1;
	int x,y,xx,yy;
	while(!q.empty()){
		tie(x,y)=q.front(); q.pop();
		REP(i,4){
			xx=x+dx[i],yy=y+dy[i];
			if(xx<0||xx>=n||yy<0||yy>=m||a[xx][yy]==-1||a[xx][yy]>mid||vis[xx][yy]) continue;
			if(xx==ex&&yy==ey) return 1;
			q.emplace(xx,yy),vis[xx][yy]=1;
		}
	}
	return 0;
}
int main(){Rosario
	int l=1e9,r=0;
	cin>>n>>m>>sx>>sy>>ex>>ey>>t;
	memset(a,-1,sizeof(a));
	for(int x,y,v;t;--t){
		cin>>x>>y>>v;
		a[x][y]=v;
		l=min(l,v);
		r=max(r,v);
	}
	a[sx][sy]=a[ex][ey]=0;
	while(l<r){
		int mid=l+r>>1;
		if(ck(mid)) r=mid;
		else l=mid+1;
	}
	cout<<l;
	return 0;
}
