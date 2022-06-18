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

int n,m,a[2000005],dq[2000005],l=0,r=0;
int main(){Rosario
    cin>>n>>m;
    REP(i,n) cin>>a[i];
    REP(i,n){
        while(r>l&&i-dq[l]>=m) l++;
        while(r>l&&a[i]>a[dq[r-1]]) r--;
        dq[r++]=i;
        if(i+1>=m) cout<<a[dq[l]]<<"\n";
    }
//    system("pause");
    return 0;
}
