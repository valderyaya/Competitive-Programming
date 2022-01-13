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

int n,x;
set<pair<int,string>> se;
string s;
signed main(){Aincrad
	cin>>n;
	while(n--){
		cin>>s;
		if(s[0]=='b'){
			cin>>s>>x;
			se.insert({x,s});
		}else if(s[0]=='f'){
			cin>>s>>x;
			if(se.count({x,s})) cout<<"YES\n";
			else cout<<"NO\n";
		}else if(s[0]=='k'){
			cin>>s>>x;
			if(se.find({x,s})!=se.end()) se.erase({x,s});
		}else if(s[0]=='y') cout<<se.begin()->S<<' '<<se.begin()->F<<"\n";
	}
	return 0;
}
