#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define F first
#define S second
#define REP(i,n) for(int i=0;i<(n);i++)
#define REP1(i,a,b) for(int i=(a);i<=(b);i++)
#define em emplace_back
#define ALL(x) (x).begin(),(x).end()
#define mkp make_pair
#define pii pair<int,int>
#define pll pair<ll,ll>
#define Rosario ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//#define lb(x) (x&-x)

ll dp[21]={0,0,1},n;
int main(){Rosario
    for(int i=3;i<=20;i++) dp[i]=(i-1)*(dp[i-1]+dp[i-2]);
    while(cin>>n,n) cout<<dp[n]<<"\n";
//    system("pause");
    return 0;
}
