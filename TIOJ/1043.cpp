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

ll dp[10005],a[105],n,m;
int main(){
    oi;
    while(cin>>n>>m,n){
        REP1(i,1,m) dp[i]=0;
        dp[0]=1;
        REP(i,n) cin>>a[i];
        REP(i,n){
            for(int j=a[i];j<=m;j++){
                dp[j]+=dp[j-a[i]];
            }
        }
        cout<<dp[m]<<"\n";
    }
//    system("pause");
    return 0;
}
