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

#define int ll
const int mod=998244353;
int n,f[1000005]={1},b[1000005],ans;
void add(int x,int v){
    for(;x<=n;x+=lb(x)) b[x]+=v;
}
int que(int x){
    int res=0;
    for(;x;x-=lb(x)) res+=b[x];
    return res;
}
main(){Rosario
    cin>>n;
    REP1(i,1,n) add(i,1),f[i]=f[i-1]*i%mod;
    for(int i=1,x;i<=n;++i){
        cin>>x;
        ans=(ans+(que(x)-1)*f[n-i]%mod)%mod;
        add(x,-1);
    }cout<<ans+1;
    return 0;
}
