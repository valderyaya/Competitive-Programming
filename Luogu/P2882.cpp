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

const int z=5005;
int ans=1e9,mx=1e9,cnt[z],a[z],n,now;
void run(int k){
	memset(cnt,0,sizeof(cnt)); int c=0,now=0;
	REP(i,n){
		now+=cnt[i];
		if((now%2)^a[i]){
			if(i+k>n) return;
			++now,--cnt[i+k]; ++c;
		}
	}
	if(c<mx) mx=c,ans=k;
}
int main(){Rosario
	cin>>n; char c;
	REP(i,n) cin>>c,a[i]=(c=='B');
	REP1(i,1,n) run(i);
	cout<<ans<<' '<<mx<<"\n";
	return 0;
}
