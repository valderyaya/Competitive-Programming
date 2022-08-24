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

const int inf=1e9+5;
struct qwq{
	int h,w,id;
	bool operator<(const qwq &x)const{
		return h==x.h?w>x.w:h>x.h;
	}
}a[200005],b[200005];
int t,n,ans[200005];
pii c[200005];
int fet(int x){
	int l=1,r=n+1;
	while(l<r){
		int mid=l+r>>1;
		if(b[mid].h>=x) l=mid+1;
		else r=mid;
	}
	return l;
}
int main(){Rosario
	cin>>t;
	while(t--){
		cin>>n;
		REP1(i,1,n){
			cin>>a[i].h>>a[i].w;
			a[i].id=i, b[i]=a[i];
			ans[i]=-1;
		}
		sort(b+1,b+1+n);
		c[n]={b[n].w,b[n].id};
		for(int i=n-1;i;--i){
			if(b[i].w<c[i+1].F) c[i]={b[i].w,b[i].id};
			else c[i]=c[i+1];
		}
		// cout<<"---\n";
		// REP1(i,1,n) cout<<b[i].h<<' '<<b[i].w<<endl;
		// cout<<"---\n";
		// REP1(i,1,n) cout<<c[i].F<<' '<<c[i].S<<endl;
		// cout<<"---\n";
		REP1(i,1,n){
			int x=fet(a[i].h);
			if(x<=n&&a[i].w>c[x].F) ans[i]=c[x].S;
		}
		REP1(i,1,n) swap(b[i].h,b[i].w);
		sort(b+1,b+1+n);
		c[n]={b[n].w,b[n].id};
		for(int i=n-1;i;--i){
			if(b[i].w<c[i+1].F) c[i]={b[i].w,b[i].id};
			else c[i]=c[i+1];
		}
		REP1(i,1,n){
			int x=fet(a[i].h);
			if(x<=n&&a[i].w>c[x].F) ans[i]=c[x].S;
		}
		REP1(i,1,n) cout<<ans[i]<<" \n"[i==n];
	}
	return 0;
}
