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
#define lb(x) (x&-x)


const int mod=10007;
int n,cnt,w[200005],mx,sum;
vector<int> v[200005];
int main(){Rosario
	cin>>n;
	for(int x,y,i=1;i<n;++i) cin>>x>>y,v[x].em(y),v[y].em(x);
	REP1(i,1,n) cin>>w[i];
	REP1(i,1,n){
		int mx1=0,mx2=0,s1=0,s2=0;
		for(auto &j:v[i]){
			if(w[j]>mx1) mx2=mx1,mx1=w[j];
			else if(w[j]>mx2) mx2=w[j];
			s1=(s1+w[j])%mod;
			s2=(s2+w[j]*w[j]%mod)%mod;
		}
		mx=max(mx,mx1*mx2);
		sum=(sum+(s1*s1%mod+mod-s2))%mod;
	}
	cout<<mx<<' '<<sum;
	return 0;
}
