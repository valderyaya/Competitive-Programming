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

const int z=2e5+5;
int ans,now,last[z],sum[z],cnt[z],col,p,k,n,val;
signed main(){Rosario
    cin>>n>>k>>p;
    REP1(i,1,n){
        cin>>col>>val;
        if(val<=p) now=i;
        if(now>=last[col]) sum[col]=cnt[col];
        last[col]=i, ans+=sum[col];
        cnt[col]++;
    }cout<<ans;
    return 0;
}
