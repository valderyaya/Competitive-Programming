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

ll n,ans;
pll a[100005];
priority_queue<ll,vector<ll>,greater<ll>> q;
signed main(){Rosario
    cin>>n;
    REP(i,n) cin>>a[i].F>>a[i].S;
    sort(a,a+n);
    REP(i,n){
        if(a[i].F<=q.size()){
            if(a[i].S>q.top()){
                ans+=a[i].S-q.top();
                q.pop(); q.emplace(a[i].S);
            }
        }else q.emplace(a[i].S),ans+=a[i].S;
    }
    cout<<ans;
    return 0;
}
