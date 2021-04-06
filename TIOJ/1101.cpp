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

int a,b,c,d,n,m;
int main(){Rosario
    while(cin>>n>>m,n||m){
		if(n==1){
			cout<<(m==1?"0/1":"1/0")<<"\n";
			continue;
		}
		a=d=0,b=c=1;
		--m; n-=2;
		string x="";
		while(m||n){
			if(m==0) x.push_back('0');
			else {
				x.push_back((m%2?'1':'0'));
				m/=2;
			}--n;
		}
		for(auto &i:x){
			if(i=='0') a+=c,b+=d;
			else c+=a,d+=b;
		}cout<<c+d<<'/'<<a+b<<"\n";
	}
    return 0;
}
