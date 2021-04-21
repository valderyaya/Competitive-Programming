//#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#include<bits/stdc++.h>
//#include<bits/extc++.h>
//using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
#define F first
#define S second
#define pb push_back
#define REP(i,n) for(register int i=0;i<(n);++i)
#define REP1(i,a,b) for(register int i=(a);i<=(b);++i)
#define ALL(x) (x).begin(),(x).end()
#define pii pair<int,int>
#define pll pair<ll,ll>
#define Rosario ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//#define lb(x) (x&-x)

pii a[2005];
int n,k,v[2002][2002],f[2002];
int dp(){
    sort(a,a+n);
    REP1(i,1,n){
        int mx=f[i-1];
        for(int j=i;j<=n;++j){
            int tmp=f[j];
            f[j]=mx+v[a[j-1].S][i];
            mx=max(mx,tmp);
            if(f[j]>=k) return i;
        }
    }return -1;
}
int main(){Rosario
    cin>>n>>k;
    REP(i,n) cin>>a[i].F,a[i].S=i+1;
    REP1(i,1,n) REP1(j,1,n) cin>>v[i][j];
    cout<<dp();
    return 0;
}
