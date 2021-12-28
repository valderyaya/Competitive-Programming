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
 
ll f[20]={0,9},n,m,q,l[20]={0,1};
signed main(){Aincrad
	for(int i=2;i<=18;++i) l[i]=i,f[i]=f[i-1]*10;
	cin>>q;
	while(q--){
		cin>>n;
		for(int i=1;i<19;++i){
			if(n<=f[i]*l[i]){
				m=f[i]/9+(n-1)/l[i];
				//cout<<m<<endl;
				for(;n%i;++n) m/=10;
				cout<<m%10<<"\n";
				break;
			}
			n-=f[i]*l[i];
		}
	}
	return 0;
}
