//#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#include<bits/stdc++.h>
//#include<bits/extc++.h>
//using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
#define F first
#define S second
#define REP(i,n) for(int i=0;i<(n);++i)
#define REP1(i,a,b) for(int i=(a);i<=(b);++i)
#define em emplace_back
#define ALL(x) (x).begin(),(x).end()
#define mkp make_pair
#define pii pair<int,int>
#define pll pair<ll,ll>
#define Rosario ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//#define lb(x) (x&-x)

const ll inf =1LL<<33;
ll now=1,dp[2][3005]={},n,m,d,lm;
pll a[3005];
int main(){Rosario
    cin>>n>>m>>lm>>d;
    REP1(i,1,n) cin>>a[i].F>>a[i].S;
    sort(a+1,a+n+1);
    REP1(i,1,n) dp[0][i]=-inf;
    REP1(i,1,m){
        REP1(j,1,n) dp[now][j]=0;
        deque<int> dq;
        REP(j,n){
            while(!dq.empty()&&a[dq.front()].F+d<a[j].F) dq.pop_front();
            while(!dq.empty()&&dp[now^1][dq.back()]<dp[now^1][j]) dq.pop_back();
            dq.push_back(j); dp[now][j+1]=dp[now^1][dq.front()]+a[j+1].S;
        }now^=1;
    }
    now^=1;
    cout<<*max_element(dp[now]+1,dp[now]+1+n)<<"\n";
    return 0;
}
