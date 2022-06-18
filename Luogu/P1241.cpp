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

string s;
stack<int> st;
char c[105];
int main(){Rosario
	cin>>s;
	REP(i,s.size()){
		if(s[i]==']'||s[i]==')'){
			if(st.empty()||c[st.top()]!=s[i]){
				if(s[i]==']') c[i]='[';
				else c[i]='(';
			}else c[st.top()]=' ',st.pop();
		}else if(s[i]=='['){
			st.emplace(i);
			c[i]=']';
		}else if(s[i]=='('){
			st.emplace(i);
			c[i]=')';
		}
	}
	REP(i,s.size()){
		if(c[i]=='('||c[i]=='[') cout<<c[i];
		cout<<s[i];
		if(c[i]==')'||c[i]==']') cout<<c[i];
	}
	return 0;
}
