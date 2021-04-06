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
#define pb push_back
#define ALL(x) (x).begin(),(x).end()
#define pii pair<int,int>
#define pll pair<ll,ll>
#define Rosario ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//#define lb(x) (x&-x)

const int z=10000,mod=10000;
int ans[z+5],n;
int main(){Rosario
    REP1(i,0,z) ans[i]=1;
    REP1(i,1,z) REP(j,2) REP1(k,i+1,z) ans[k]=(ans[k]+ans[k-1])%mod;
    while(cin>>n,n){
        if(n<8) cout<<ans[n]<<"\n";
        else cout<<setw(4)<<setfill('0')<<ans[n]<<"\n";
    }
    return 0;
}
