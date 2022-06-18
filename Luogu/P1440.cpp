//#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#include<bits/stdc++.h>
#include<bits/extc++.h>
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

int n,m,a[2000005],dp[2000005]={},l=0,r=0;
int main(){Rosario
    cin>>n>>m;cout<<"0\n";
    REP1(i,1,n) cin>>a[i];
    REP1(i,1,n-1){
        while(r>l&&i-dp[l]>=m) l++;
        while(r>l&&a[dp[r-1]]>=a[i]) r--;
        dp[r++]=i;
        cout<<a[dp[l]]<<"\n";
    }
//    system("pause");
    return 0;
}
