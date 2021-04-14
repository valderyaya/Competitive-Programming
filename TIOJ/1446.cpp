#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
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

int n,sum=0,lcp=0;
string s[100001];
int main(){Rosario
    cin>>n;
	REP(i,n) cin>>s[i],sum+=s[i].size();
	sort(s,s+n);
	for(int i=1;i<n;++i){
		int o=min(s[i-1].size(),s[i].size());
		for(int j=0;j<o&&s[i-1][j]==s[i][j];++j,++lcp);
	}cout<<(sum-lcp)*2+n<<"\n";
    return 0;
}
