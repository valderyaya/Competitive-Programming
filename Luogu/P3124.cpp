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

int n,m,ans=2147483647;
struct qq{
	int s,p;
	bool operator<(const qq &x)const{return p<x.p;}
}a[100005];
int main(){Rosario
    cin>>n>>m;
	REP1(i,1,n) cin>>a[i].s>>a[i].p;
	sort(a+1,a+1+n);
	int now=1;
	for(;now<=n&&a[now].p<m;++now);
	--now;
	for(int l=now,r=l+1;l>0;--l){
		while(r<=n&&a[r].p-a[l].p>a[r].s) ++r;
		if(r>n) break;
		ans=min(ans,a[r].p-a[l].p-a[l].s);
	}
	for(int l=now,r=l+1;r<=n;++r){
		while(l>0&&a[r].p-a[l].p>a[l].s) --l;
		if(l<1) break;
		ans=min(ans,a[r].p-a[l].p-a[r].s);
	}
	cout<<(ans==2147483647?-1:max(ans,0))<<"\n";
    return 0;
}
