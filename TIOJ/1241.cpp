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

int t,n,cnt[2005],ans;
int main(){Rosario
    cin>>t;
	while(t--){
		cin>>n; memset(cnt,0,sizeof(cnt)); ans=0;
		REP1(i,1,n)
			if(cnt[i]<n/i-1) for(int j=i<<1;j<=n;j+=i) ++cnt[j];
			else ans+=cnt[i];
		cout<<ans<<"\n";
	}
    return 0;
}
