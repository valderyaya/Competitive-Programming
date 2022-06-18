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

#define int ll
const int mod=1000000;
int n,ans;
set<int> a,b;
 main(){Rosario
	cin>>n;
	for(int x,y;n;--n){
		cin>>x>>y;
		if(x==0){
			if(!b.empty()){
				auto it=b.lower_bound(y);
				if(it==b.end()) it=prev(it);
				if(it!=b.begin()&&y-*prev(it)<=*it-y){
					ans+=abs(y-*prev(it));
					b.erase(prev(it));
				}else{
					ans+=abs(y-*it);
					b.erase(it);
				}
				ans%=mod;
			}else a.insert(y);
		}else if(x==1){
			if(!a.empty()){
				auto it=a.lower_bound(y);
				if(it==a.end()) it=prev(it);
				if(it!=a.begin()&&y-*prev(it)<=*it-y){
					ans+=abs(y-*prev(it));
					a.erase(prev(it));
				}else{
					ans+=abs(y-*it);
					a.erase(it);
				}
				ans%=mod;;
			}else b.insert(y);
		}
	}
	cout<<ans;
	return 0;
}
