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
#define lb(x) (x&-x)

int k,n;
vector<int> dp;
int main(){//Rosario
    dp.em(1),dp.em(1);
    for(int i=2;i<=45;i++) dp.em(dp[i-1]+dp[i-2]);
    cin>>n;
    while(n--){
        cin>>k;
        int c=0;
        for(int i=dp.size()-1;i>0;i--){
            if(dp[i]<=k) k-=dp[i],c++;
        }
        if(k) cout<<"iyada~\n";
        else cout<<c<<"\n";
    }
//    system("pause");
    return 0;
}
