//#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#include<bits/stdc++.h>
//#include<bits/extc++.h>
//using namespace __gnu_pbds;
using namespace std;
#define F first
#define S second
typedef long long ll;
#define REP(i,n) for(int i=0;i<(n);++i)
#define REP1(i,a,b) for(int i=(a);i<=(b);++i)
#define em emplace_back
#define mkp make_pair
#define ALL(x) (x).begin(),(x).end()
#define pii pair<int,int>
#define pll pair<ll,ll>
#define Rosario ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//#define lb(x) (x&-x)

string s;
map<string,int> m;
stack<int> st;
int a[260];
int main(){Rosario
    cin>>s;
	cout<<s<<"\n";
	REP(i,s.size()){
		if(isdigit(s[i])){
			int x=s[i]-'0',j;
			for(j=i+1;j<s.size()&&isdigit(s[j]);++j) x=x*10+s[j]-'0';
			a[i-1]*=x; i=j-1;
		}else if(s[i]==')'){
			int x=0,j;
			for(j=i+1;j<s.size()&&isdigit(s[j]);++j) x=x*10+s[j]-'0';
			if(x>1) for(int k=st.top()+1;k<i;++k) a[k]*=x;
			st.pop(); i=j-1;
		}else if(s[i]=='(') st.emplace(i);
		else a[i]=1;
	}string tmp;
	REP(i,s.size()){
		if(s[i]<='Z'&&s[i]>='A'){
			tmp=s[i];
			if(i+1<s.size()&&s[i+1]<='z'&&s[i+1]>='a') tmp+=s[i+1],m[tmp]+=max(a[i],a[i+1]);
			else m[tmp]+=a[i];
		}
	}
	for(auto &i:m) cout<<i.F<<':'<<i.S<<"\n";
    return 0;
}
