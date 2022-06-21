#include<bits/stdc++.h>
using namespace std;
#define valder ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define ll long long
#define F first
#define S second
#define ALL(x) x.begin(),x.end()
#define pii pair<int,int>
#define REP(i,n) for(int i=0;i<n;++i)
#define REP1(i,a,b) for(int i=a;i<=b;++i)
#define em emplace_back
#define lb(x) x&-x
#define pll pair<ll,ll>
#define mkp make_pair
#define endl "\n"

string s;
signed main(){valder
	cin>>s;
	if(s.size()==3) cout<<s<<s;
	else if(s.size()==2) cout<<s<<s<<s;
	else for(int i=0;i<6;++i) cout<<s;
	return 0;
}
