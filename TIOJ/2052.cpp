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

int d,c[1025][1025],ans;
string s;
map<int,int> mp;
int main(){Rosario
	cin>>d>>s;
	for(auto &i:s) mp[i]++;
	REP(i,1025){
		c[i][0]=1;
		REP1(j,1,i) c[i][j]=(c[i-1][j-1]+c[i-1][j])%d; 
	}
	REP(i,s.size()){
		for(auto &j:mp){
			if(j.F==s[i]) break;
			int tmp=1,len=s.size()-i-1;
			--j.S;
			for(auto &k:mp) tmp=(tmp*c[len][k.S])%d, len-=k.S;
			++j.S;
			ans=(ans+tmp)%d;
		}
		if(--mp[s[i]]==0) mp.erase(s[i]);
	}
	cout<<ans<<"\n";
	return 0;
}
