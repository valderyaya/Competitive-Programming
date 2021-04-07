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
#define lb(x) (x&-x)

ll f[45],n;
int main(){Rosario
    f[1]=1;f[3]=4;
    for(int i=5;i<=41;i+=2) {
        f[i]=f[i-2]*3+1;
        for(int j=4;i-j>0;j+=2) f[i]+=2*f[i-j];
    }
    while(cin>>n) cout<<f[n]<<"\n";
    return 0;
}
