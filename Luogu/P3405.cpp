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

int mp[700][700],ans,n,x,y;
string a,b;
int main(){Rosario
	cin>>n;
	while(n--){
		cin>>a>>b;
		x=(a[0]-65)*26+a[1]-65;
		y=(b[0]-65)*26+b[1]-65;
		if(x!=y) ++mp[x][y],ans+=mp[y][x];
	}cout<<ans;
	return 0;
}
