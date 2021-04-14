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

int n,idx=0;
bitset<1000001> del;
priority_queue<pii,vector<pii>,greater<pii>> mn;
priority_queue<pii,vector<pii>> mx;
ll sum=0;
int main(){Rosario
	while(cin>>n){
	sum=idx=0; del.reset();
	while(!mx.empty()) mx.pop();
	while(!mn.empty()) mn.pop();
	for(int x,y;n;--n){
		cin>>x;
		while(x--) cin>>y,++idx,mx.push({y,idx}),mn.push({y,idx});
		while(!mx.empty()&&del[mx.top().S]) mx.pop();
		while(!mn.empty()&&del[mn.top().S]) mn.pop();
		del[mn.top().S]=1,del[mx.top().S]=1;
		sum+=mx.top().F-mn.top().F;
		mx.pop(); mn.pop();
	}
	cout<<sum<<"\n";
	}
	return 0;
}
