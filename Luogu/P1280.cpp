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
#define wait system("pause");

struct qq{
    int st,ed;
    bool operator<(const qq &x)const{
        return st>x.st;
    }
}a[10005];
int dp[10005],cnt[10005],n,m,idx=0;
int main(){Rosario
    cin>>n>>m;
    REP(i,m) cin>>a[i].st>>a[i].ed,cnt[a[i].st]++;
    sort(a,a+m);
    for(int i=n;i;--i){
        if(!cnt[i]) dp[i]=dp[i+1]+1;
        else for(int j=0;j<cnt[i];j++,idx++) dp[i]=max(dp[i],dp[i+a[idx].ed]);
    }
    cout<<dp[1]<<"\n";
//    system("pause");
    return 0;
}
