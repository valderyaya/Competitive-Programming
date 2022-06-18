//#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#include<bits/stdc++.h>
//#include<bits/extc++.h>
//using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
#define F first
#define S second
#define pb push_back
#define em emplace_back
#define REP(i,n) for(register int i=0;i<(n);++i)
#define REP1(i,a,b) for(register int i=(a);i<=(b);++i)
#define ALL(x) (x).begin(),(x).end()
#define pii pair<int,int>
#define pll pair<ll,ll>
#define Rosario ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//#define lb(x) (x&-x)

const int z=2e3+5;
string s1,s2;
int f[z][z],k;
signed main(){Rosario
    cin>>s1>>s2>>k;
    REP1(i,1,s1.size()) f[i][0]=i*k;
    REP1(i,1,s2.size()) f[0][i]=i*k;
    REP1(i,1,s1.size()) REP1(j,1,s2.size())
        f[i][j]=min({f[i][j-1]+k,f[i-1][j]+k,f[i-1][j-1]+abs(s1[i-1]-s2[j-1])});
    cout<<f[s1.size()][s2.size()]<<"\n";
    return 0;
}
