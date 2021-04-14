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
ll f[10005]={1,1},n,m;
int main(){Rosario
    while(cin>>s,s!="0"){
        s="9"+s; n=s.size();
        REP1(i,2,n-1){
            if(s[i]=='0') f[i]=f[i-2];
            else{
                m=10*(s[i-1]-'0')+s[i]-'0';
                f[i]= (m>10&&m<27)?f[i-1]+f[i-2]:f[i-1];
            }
        }
        cout<<f[n-1]<<"\n";
    }
    return 0;
}
