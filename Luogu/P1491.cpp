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

struct edge{
	int to,nxt;
	double w;
}e[40000];
int cnt,n,m,h[205],pre[205];
pii p[205];
double d[205],ans=1e9;
double cal(int i,int j){
	return sqrt((p[i].F-p[j].F)*(p[i].F-p[j].F)+(p[i].S-p[j].S)*(p[i].S-p[j].S));
}
void add(int u,int v,double w){
	e[++cnt]=edge{v,h[u],w};
	h[u]=cnt;
}
#define pdi pair<double,int>
priority_queue<pdi,vector<pdi>,greater<pdi>>q;
void dijk(int u,int pr){
	REP1(i,2,n) d[i]=1e9;
	q.emplace(0,1);
	while(!q.empty()){
		double dis=q.top().F;
		int x=q.top().S; q.pop();
		if(d[x]!=dis) continue;
		for(int i=h[x];i;i=e[i].nxt){
			int v=e[i].to;
			if((u==x&&pr==v)||(u==v&&pr==x)) continue;
			double t=dis+e[i].w;
			if(d[v]>t){
				if(u==-1&&pr==-1) pre[v]=x;
				d[v]=t;
				q.emplace(t,v);
			}
		}
	}
}
int main(){Rosario
	cin>>n>>m;
	REP1(i,1,n) cin>>p[i].F>>p[i].S;
	for(int x,y;m;--m){
		cin>>x>>y;
		double c=cal(x,y);
		add(x,y,c); add(y,x,c);
	}
	dijk(-1,-1);
	for(int i=n;i!=1;i=pre[i]){
		dijk(i,pre[i]);
		ans=min(ans,d[n]);
	}
	if(ans==1e9) cout<<"-1";
	else cout<<fixed<<setprecision(2)<<ans<<'\n';
	return 0;
}
