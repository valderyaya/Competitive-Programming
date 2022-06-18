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
#define lb(x) (x&-x)

int n,m,ans,a[500005];
deque<int> dq;
signed main(){Rosario
    cin>>n>>m; dq.push_back(0);
    REP1(i,1,n) cin>>a[i],a[i]+=a[i-1];
    REP1(i,1,n){
        while(i-dq.front()>m) dq.pop_front();
        ans=max(ans,a[i]-a[dq.front()]);
        while(!dq.empty()&&a[dq.back()]>a[i]) dq.pop_back();
        dq.emplace_back(i);
    }
    cout<<ans<<"\n";
    return 0;
}
