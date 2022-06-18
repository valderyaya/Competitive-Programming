//#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#include<bits/stdc++.h>
//#include<bits/extc++.h>
//using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
#define F first
#define S second
#define REP(i,n) for(int i=0;i<(n);++i)
#define REP1(i,a,b) for(int i=(a);i<=(b);++i)
#define em emplace_back
#define ALL(x) (x).begin(),(x).end()
#define mkp make_pair
#define pii pair<int,int>
#define pll pair<ll,ll>
#define Rosario ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//#define lb(x) (x&-x)

int m[]={0,31,28,31,30,31,30,31,31,30,31,30,31};
string res(int x){
    string re="";
    if(x<10) re="0",re+=char(x+'0');
    else re=char(x/10+'0'),re+=char(x%10+'0');
    return re;
}
string s,p[400];
int main(){//Rosario
    cin>>s; int idx=0,ans=10;
    REP1(i,1,12) REP1(j,1,m[i]) p[++idx]=res(i)+"-"+res(j);
    //REP1(i,1,50) cout<<p[i]<<endl;
    REP1(i,1,idx){
        int x=0;
        REP(j,5) if(s[j]!=p[i][j]) ++x;
        ans=min(ans,x);
    }cout<<ans;
    return 0;
}
