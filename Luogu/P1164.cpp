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
#define oi ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define lb(x) (x&-x)

int n,m,dp[10005]={1},a[1005];
int main(){
    oi;
    cin>>n>>m;
    REP(i,n) cin>>a[i];
    REP(i,n){
        for(int j=m;j>=a[i];j--) dp[j]+=dp[j-a[i]];
    }
    cout<<dp[m]<<"\n";
//    system("pause");
    return 0;
}
