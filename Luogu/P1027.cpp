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

const int z=405;
struct qwq{int x,y,ct;}a[z];
double dis[z];
int t,n,st,ed,s,T[z];
void get_(int x1,int y1,int x2,int y2,int x3,int y3,int x){
	int ab=(x1-x2)*(x1-x2)+(y1-y2)*(y1-y2),
		ac=(x1-x3)*(x1-x3)+(y1-y3)*(y1-y3),
		bc=(x3-x2)*(x3-x2)+(y3-y2)*(y3-y2),x4,y4;
	if(ab+ac==bc) x4=x3-x1+x2,y4=y3-y1+y2;
	if(ab+bc==ac) x4=x3-x2+x1,y4=y3-y2+y1;
	if(ac+bc==ab) x4=x1-x3+x2,y4=y1-y3+y2;
	a[x+3].x=x4,a[x+3].y=y4;
}
double distance_(int x,int y){
	return sqrt((a[x].x-a[y].x)*(a[x].x-a[y].x)+(a[x].y-a[y].y)*(a[x].y-a[y].y));
}
#define pp pair<double,int>
priority_queue<pp,vector<pp>,greater<pp>> q;
void dijk(){
	REP1(i,1,n*4) dis[i]=1e9;
	for(int i=st*4-3;i<=st*4;++i) q.emplace(dis[i]=0,i);
	while(!q.empty()){
		double d=q.top().F; int x=q.top().S; q.pop();
		if(d>dis[x]) continue;
		REP1(i,1,4*n){
			if(i==x) continue;
			double df=distance_(i,x);
			if(a[i].ct==a[x].ct) df*=T[a[i].ct];
			else df*=s;
			if(dis[i]>d+df){
				dis[i]=d+df;
				q.emplace(dis[i],i);
			}
		}
	}
}
int main(){Rosario
	cin>>t;
	while(t--){
		cin>>n>>s>>st>>ed;
		for(int i=1;i<=n*4;i+=4){
			cin>>a[i].x>>a[i].y>>a[i+1].x>>a[i+1].y>>a[i+2].x>>a[i+2].y>>T[i/4+1];
			a[i].ct=a[i+1].ct=a[i+2].ct=a[i+3].ct=a[i+4].ct=(i/4+1);
			get_(a[i].x,a[i].y,a[i+1].x,a[i+1].y,a[i+2].x,a[i+2].y,i);
		}
		dijk();
		double ans=1e9;
		for(int i=ed*4-3;i<=ed*4;++i) ans=min(ans,dis[i]);
		cout<<fixed<<setprecision(1)<<ans<<"\n";
	}
	return 0;
}
