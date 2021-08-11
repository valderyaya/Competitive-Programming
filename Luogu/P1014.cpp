//#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#include<bits/stdc++.h>
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

int n,sum=0,i;
int main(){Rosario
    cin>>n;
    for(i=1;;i++){
        if(sum+i>=n) break;
        sum+=i;
    }n-=sum;
    if(i&1) cout<<i-n+1<<'/'<<n<<"\n";
    else cout<<n<<'/'<<i-n+1<<"\n";
//    system("pause");
    return 0;
}
