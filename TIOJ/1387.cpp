#include<bits/stdc++.h>
// #include<ext/rope>
// using namespace __gnu_cxx;
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define REP1(i,a,b) for(int i=(a);i<=(b);i++)
#define pii pair<int,int>
typedef long long ll;
#define mkp make_pair
#define em emplace_back
#define F first
#define S second
#define ALL(x) (x).begin(),(x).end()
#define Rosario ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define pll pair<ll,ll>
#define lb(x) (x&-x)

int d,w[55],c[55],m[55],dp[10005]={},n;
int main(){Rosario
    cin>>n;
    REP(i,n) cin>>w[i]>>m[i]>>c[i];
    cin>>d;
    REP(i,n)
        while(c[i]--)
            for(int j=d;j>=w[i];j--) dp[j]=max(dp[j],dp[j-w[i]]+m[i]);
    cout<<dp[d]<<"\n";
//    system("pause");
    return 0;
}
