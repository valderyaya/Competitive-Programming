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
//#define line cout<<"-------------------------\n";

int n,dp[6005][2]={},in[6005]={};
vector<int> v[6005];
void dfs(int x){
    for(auto &i:v[x]){
        dfs(i);
        dp[x][0]+=max(dp[i][1],dp[i][0]);
        dp[x][1]+=dp[i][0];
    }
}
int main(){Rosario
    cin>>n;
    REP1(i,1,n) cin>>dp[i][1];
    for(int x,y,i=0;i<n-1;i++) cin>>x>>y,v[y].em(x),in[x]++;
    REP1(i,1,n) if(!in[i]){
        dfs(i);
        cout<<max(dp[i][0],dp[i][1])<<"\n";
        break;
    }
//    system("pause");
    return 0;
}
