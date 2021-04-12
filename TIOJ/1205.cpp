//#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#include<bits/stdc++.h>
//#include<bits/extc++.h>
//using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
#define F first
#define S second
#define REP(i,n) for(register int i=0;i<(n);++i)
#define REP1(i,a,b) for(register int i=(a);i<=(b);++i)
#define em emplace_back
#define ALL(x) (x).begin(),(x).end()
#define mkp make_pair
#define pii pair<int,int>
#define pll pair<ll,ll>
#define Rosario ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define lb(x) (x&-x)
//#define line cout<<"-------------------------\n";

map<pii,int> m;
int n,ans;
pii a[1505];
int main(){Rosario
    while(cin>>n,n){ans=0;
		REP1(i,1,n) cin>>a[i].F>>a[i].S;
		REP1(i,1,n){
			m.clear();
			REP1(j,1,n) if(i!=j){
				int x=a[j].F-a[i].F,y=a[j].S-a[i].S,g=abs(__gcd(x,y));
				x/=g,y/=g;  m[{x,y}]++;
			}
			for(auto &i:m) ans+=i.S*m[{i.F.S,-i.F.F}];
		}cout<<ans<<"\n";
	}
    return 0;
}
