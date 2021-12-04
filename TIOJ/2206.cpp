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
#define Alicization ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define lb(x) (x&-x)

int n,f[20][100005],q;
int qry(int a,int b){
    for(int i=19;~i;--i) if(b>>i&1) a=f[i][a];
    return a;
}
signed main(){Alicization
    cin>>n;
    REP1(i,1,n) cin>>f[0][i];
    REP1(j,1,19) REP1(i,1,n) f[j][i]=f[j-1][f[j-1][i]];
    cin>>q;
    for(int a,b;q;--q) cin>>a>>b,cout<<qry(a,b)<<"\n";
    return 0;
}
