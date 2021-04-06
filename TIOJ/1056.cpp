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

string s[3];
int co=0,cx=0;
bool out=0;
bool ck(char c){
	if(s[0][0]==s[1][0]&&s[1][0]==s[2][0]&&s[2][0]==c) return 1;
	if(s[0][1]==s[1][1]&&s[1][1]==s[2][1]&&s[2][1]==c) return 1;
	if(s[0][2]==s[1][2]&&s[1][2]==s[2][2]&&s[2][2]==c) return 1;
	if(s[0][0]==s[0][1]&&s[0][1]==s[0][2]&&s[0][2]==c) return 1;
	if(s[1][0]==s[1][1]&&s[1][1]==s[1][2]&&s[1][2]==c) return 1;
	if(s[2][0]==s[2][1]&&s[2][1]==s[2][2]&&s[2][2]==c) return 1;
	if(s[0][0]==s[1][1]&&s[1][1]==s[2][2]&&s[2][2]==c) return 1;
	if(s[2][0]==s[1][1]&&s[1][1]==s[0][2]&&s[0][2]==c) return 1;
	return 0;
}
int main(){Rosario
    REP(i,3) cin>>s[i];
	REP(i,3) REP(j,3){
		if(s[i][j]=='O') co++;
		else if(s[i][j]=='X') cx++;
		else if(s[i][j]!='.') out=1;
	}
	if(out) cout<<"IMPOSSIBLE\n";
	else if((co-1==cx&&!ck('X'))||(co==cx&&!ck('O'))) cout<<"POSSIBLE\n";
	else cout<<"IMPOSSIBLE";
    return 0;
}
