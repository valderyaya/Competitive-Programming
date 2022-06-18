#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,n) for(int i=0;i<n;++i)
#define REP1(i,a,b) for(int i=a;i<=b;++i)
#define all(x) x.begin(),x.end()
#define em emplace_back
#define Rosario ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

string a,b;
signed main(){Rosario
	cin>>a>>b;
	for(int i=1,j=(b[0]-a[0]+26)%26;i<a.size();++i)
		if((b[i]-a[i]+26)%26!=j) return cout<<"No\n",0;
	cout<<"Yes\n";
}
