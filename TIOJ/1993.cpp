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

int t,n,m;
bitset<100005> dp;
int main(){Rosario
    cin>>t;int x,y,z;
    while(t--){dp.reset();
        cin>>n>>m; dp[0]=1;
        while(n--){
            cin>>x>>y>>z;
            dp=dp<<x|dp<<y|dp<<z;
        }int i;
        for(i=m;i&&dp[i]==0;i--);
        if(i==0) cout<<"no solution\n";
        else cout<<i<<"\n";
    }
    return 0;
}
