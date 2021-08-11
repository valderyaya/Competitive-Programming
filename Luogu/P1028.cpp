#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
#define REP(i,n) for (int i=0;i<(n);i++)
#define REP1(i,a,b) for(int i=(a);i<=(b);i++)
#define em emplace_back
#define ALL(x) (x).begin(),(x).end()
#define SZ(x) ((int)(x).size())
#define sz(x) (sizeof(x)/sizeof(*x))
#define F first
#define S second
#define mkp make_pair

int dp[1001]={1,1};
int main(){
    //ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n;
    cin>>n;
    REP1(i,2,n){
        if(i%2) dp[i]=dp[i-1];
        else dp[i]=dp[i-1]+dp[i>>1];
    }
    cout<<dp[n];
//    system("pause");
    return 0;
}
