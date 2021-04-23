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
//#define lb(x) (x&-x)
//#define line cout<<"-------------------------\n";

const int z=1500005;
int n,ans[z];
pii a[z];
stack<int> st;
bool ck(pii x,pii y){
	if((x.F>y.F&&x.S>=y.S)||(x.F>=y.F&&x.S>y.S)) return 1;
	return 0;
}
int main(){Rosario
    cin>>n;
	REP1(i,1,n) cin>>a[i].F>>a[i].S;
	REP1(i,1,n){
		while(!st.empty()&&ck(a[i],a[st.top()])) st.pop();
		if(st.empty()) ans[i]=i-1;
		else ans[i]=i-st.top()-1;
		st.emplace(i);
	}while(!st.empty()) st.pop();
	for(int i=n;i;--i){
		while(!st.empty()&&ck(a[i],a[st.top()])) st.pop();
		if(st.empty()) ans[i]+=n-i;
		else ans[i]+=st.top()-i-1;
		st.emplace(i);
	}cout<<*max_element(ans+1,ans+1+n)<<"\n";
    return 0;
}
