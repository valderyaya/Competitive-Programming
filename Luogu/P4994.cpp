//#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#include<bits/stdc++.h>
//#include<bits/extc++.h>
//using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
#define F first
#define S second
#define REP(i,n) for(register int i=0;i<(n);++i)
#define REP1(i,a,b) for(register int i=(a);i<=(b);++i)
#define em emplace_back
#define ALL(x) (x).begin(),(x).end()
#define mkp make_pair
#define pii pair<int,int>
#define pll pair<ll,ll>
#define Rosario ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//#define lb(x) (x&-x)
//#define line cout<<"-------------------------\n";

int n,dp[3]={0,0,1};
int main(){Rosario
    cin>>n;
    for(int i=3;i;++i){
        dp[i%3]=(dp[(i-1)%3]+dp[(i-2)%3])%n;
        if(dp[(i-1)%3]==0&&dp[i%3]==1){cout<<i-2<<"\n";break;}
    }
    return 0;
}
