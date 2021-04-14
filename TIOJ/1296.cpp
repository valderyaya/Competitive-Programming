#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
#define REP(i,n) for (int i=0;i<(n);i++)
#define REP1(i,a,b) for(int i=(a);i<=(b);i++)
#define em emplace_back
#define ALL(x) (x).begin(),(x).end()
#define F first
#define S second
#define pii pair<int,int>
#define mkp make_pair
#define Rosario ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//#define lb(x) (x&(-x)) 

ll n,dp[25]={0,1};
int main(){
    //Rosario
    for(int i=2;i<=20;i++) dp[i]=dp[i-1]*(4*i-2)/(i+1);
    while(cin>>n) cout<<dp[n]<<"\n";
//    system("pause");
    return 0;
}

