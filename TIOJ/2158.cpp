//#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#include<bits/stdc++.h>
//#include<bits/extc++.h>
//using namespace __gnu_pbds;
using namespace std;
#define F first
#define S second
typedef long long ll;
#define REP(i,n) for(int i=0;i<(n);++i)
#define REP1(i,a,b) for(int i=(a);i<=(b);++i)
#define em emplace_back
#define mkp make_pair
#define ALL(x) (x).begin(),(x).end()
#define pii pair<int,int>
#define pll pair<ll,ll>
#define Rosario ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//#define lb(x) (x&-x)

int n,m,now[2005]={},vis[2005]={},cnt=0,idx=0;
vector<int> s;
struct qq{int x,y,w;}q[2005];
struct lolicon{
	int dis,a,b;
	bool operator<(const lolicon &x)const{return dis<x.dis;}
}cute[4000005];
pii b[2005];
void add(int x){if(vis[x]++==0) ++cnt;}
void sub(int x){if(--vis[x]==0) --cnt;}
int solve(){
    int mx=0,nw=0;
	sort(cute,cute+idx);
	sort(ALL(s)); s.resize(unique(ALL(s))-s.begin());
    for(auto &i:s){
		for(;nw<idx&&cute[nw].dis<=i;++nw){
			auto &it=cute[nw];
			if(now[it.a]){
				if(q[now[it.a]].w<q[it.b].w){
					sub(now[it.a]);
					add(now[it.a]=it.b);
				}
			}else add(now[it.a]=it.b);
		}
        mx=max(mx,cnt);
    }
    return mx;
}
int main(){Rosario
    cin>>n>>m; 
    for(int i=1;i<=n;++i) cin>>q[i].x>>q[i].y>>q[i].w;
    for(int i=1;i<=m;++i) cin>>b[i].F>>b[i].S;
    for(int i=1;i<=m;++i)
        for(int j=1;j<=n;++j){
			int x=max(abs(b[i].F-q[j].x),abs(b[i].S-q[j].y));
            cute[idx++]=lolicon{x,i,j}; s.em(x);
		}
	cout<<solve()<<"\n";
    return 0;
}
