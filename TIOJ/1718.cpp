//#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
//#include<bits/extc++.h>
//using namespace __gnu_pbds;
typedef long long ll;
using namespace std;
#define REP(i,n) for (int i=0;i<(n);i++)
#define REP1(i,a,b) for(int i=(a);i<=(b);i++)
#define em emplace_back
#define ALL(x) (x).begin(),(x).end()
#define F first
#define S second
#define mkp make_pair
#define pii pair<int,int>
#define Rosario ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define pll pair<ll,ll> 
//#define lb(x) (x&-x)
//#define line cout<<"-------------------------------\n";


int dp[10001],n,m,p;
vector<pii> v[51];
int main(){Rosario
    cin>>n>>m>>p;
    REP(i,m){
        v[i].resize(p);
        REP(j,p) cin>>v[i][j].F>>v[i][j].S;
    }
    REP(i,m)
        for(int j=n;j>=0;j--)
            for(auto &k:v[i]) if(j-k.F>=0) dp[j]=max(dp[j],dp[j-k.F]+k.S);
    cout<<dp[n]<<"\n";
//    system("pause");
    return 0;
}
