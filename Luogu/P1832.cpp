//#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#include<bits/stdc++.h>
//#include<bits/extc++.h>
//using namespace __gnu_pbds;
typedef long long ll;
using namespace std;
#define REP(i,n) for (int i=0;i<(n);++i)
#define REP1(i,a,b) for(int i=(a);i<=(b);++i)
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

ll dp[1001]={1},n;
vector<ll> v;
bool is[1001]={1,1,0};
int main(){//Rosario
   cin>>n;
   for(int i=2;i<=n;i++){
        if(!is[i]) v.em(i);
        for(int j:v){
            if(i*j>n) break;
            is[i*j]=1;
            if(i%j==0) break;
        }
   }
   for(auto &i:v){
       for(int j=i;j<=n;j++) dp[j]+=dp[j-i];
   }
   cout<<dp[n]<<"\n";
//    system("pause");
    return 0;
}
