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

int n,ans=1e9,f[1033],sum=0,pr=1;
pii a[10];
int main(){Rosario
    cin>>n;
    REP(i,n) cin>>a[i].F>>a[i].S;
    for(int i=1;i<(1<<n);++i){
        sum=0;pr=1;
        for(int j=0;j<10;++j)
            if(i>>j&1) sum+=a[j].S,pr*=a[j].F;
        ans=min(ans,abs(pr-sum));
    }
    cout<<ans<<"\n";
    return 0;
}
