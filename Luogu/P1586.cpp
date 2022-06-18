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

int t,n,m,a[105],c[200],dp[100005],mx=0;
int main(){Rosario
    cin>>t;
    REP1(i,1,181) c[i]=i*i;
    REP(i,t) cin>>a[i],mx=max(mx,a[i]);
    for(int i=0;i<=181;i++){
        if(c[i]>mx) break;
        for(int j=i;j<=181;j++){
            if(c[i]+c[j]>mx) break;
            for(int k=j;k<=181;k++){
                if(c[i]+c[j]+c[k]>mx) break;
                for(int l=k;l<=181;l++){
                    int x=c[i]+c[j]+c[k]+c[l];
                    if(x>mx) break;
                    dp[x]++;
                }
            }
        }
    }
    REP(i,t) cout<<dp[a[i]]<<"\n";
    return 0;
}
