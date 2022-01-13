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
#define Aincrad ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define lb(x) (x&-x)

int t,n,q,sum[5005],ss[5005];
pii a[5005];
signed main(){Aincrad
	cin>>t;
	while(t--){
		cin>>n>>q;
		int tot=0,ans=0;
		REP1(i,1,n) sum[i]=0;
		REP1(i,1,q) cin>>a[i].F>>a[i].S,++sum[a[i].F],--sum[a[i].S+1];
		REP1(i,1,n){
			sum[i]+=sum[i-1];
			ss[i]=sum[i];
			if(sum[i]) ++tot;
		}
		REP1(i,1,n){
			int cnt=tot;
			REP1(j,a[i].F,a[i].S) if(--ss[j]==0) --cnt; 
			REP1(j,1,n){
				if(i==j) continue;
				ans=max(ans,cnt-((ss[a[j].S]-ss[a[j].F-1])<2));
			}
			REP1(j,a[i].F,a[i].S) ++ss[j];
		}
		cout<<ans<<"\n";
	}
	return 0;
}
