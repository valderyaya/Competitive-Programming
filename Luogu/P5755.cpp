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

const int z=32005;
int cnt,tr[z][26];
string s;
void insert(){
	int p=0;
	for(auto &i:s){
		if(!tr[p][i-65]) tr[p][i-65]=++cnt;
		p=tr[p][i-65];
	}
}
signed main(){Rosario
	while(cin>>s) insert();
	cout<<++cnt<<"\n";
	return 0;
}
